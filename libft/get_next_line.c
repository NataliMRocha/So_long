/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:16:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/23 16:57:02 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_file	file;

	if (file.pos >= file.nb_read || file.pos == 0)
	{
		file.pos = 0;
		while (file.pos < BUFFER_SIZE)
			file.buf[file.pos++] = '\0';
		file.pos = 0;
		file.line = NULL;
		file.len = 0;
		file.fd = fd;
		file.nb_read = read(fd, file.buf, BUFFER_SIZE);
	}
	if (file.nb_read <= 0 || file.buf[file.pos] == '\0')
	{
		if (file.nb_read < 0 && file.line)
			free_file(file.line);
		return (NULL);
	}
	return (read_line_gnl(&file));
}

char	*read_line_gnl(t_file *temp)
{
	temp->len = 0;
	while (1)
	{
		put_in_pos_gnl(&temp->line, get_char_node(*(temp->buf + temp->pos)));
		if (*(temp->buf + temp->pos) == '\n'
			|| *(temp->buf + temp->pos) == '\0')
			break ;
		temp->pos++;
		temp->len++;
		if (temp->pos >= temp->nb_read)
		{
			temp->pos = 0;
			temp->nb_read = read(temp->fd, temp->buf, BUFFER_SIZE);
			if (temp->nb_read <= 0 || temp->buf[temp->pos] == '\0')
			{
				if (temp->nb_read < 0 && temp->line)
					return (free_file(temp->line));
				break ;
			}
		}
	}
	temp->len++;
	temp->pos++;
	return (get_current_line(temp));
}

char	*get_current_line(t_file *set)
{
	t_liste	*temp;
	char	*line;
	int		i;

	line = (char *)malloc((set->len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	temp = NULL;
	while (set->line)
	{
		temp = set->line->next;
		*(line + i) = set->line->char_read;
		free(set->line);
		set->line = temp;
		i++;
	}
	*(line + i) = '\0';
	return (line);
}
