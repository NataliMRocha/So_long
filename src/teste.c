/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:59:30 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/14 20:25:40 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_line(t_def **def, char *path)
{
	int		fd;
	int		size;
	int		i;
	char	buffer[1024];

	fd = open(path, O_RDONLY);
	size = read(fd, buffer, 1024);
	(*def)->map->w = 0;
	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			break ;
		(*def)->map->w++;
	}
	if ((*def)->map->w)
		(*def)->map->h = size / (*def)->map->w;
	close(fd);
}

void	create_matrix(char ***map, char *path, int w, int h)
{
	int		i;
	int		fd;
	int		j;
	int		size;
	char	buffer[65535];

	(*map) = (char **)malloc(h * sizeof(char *));
	i = -1;
	while (++i < h)
		(*map)[i] = (char *)malloc(w * sizeof(char));
	fd = open(path, O_RDONLY);
	size = read(fd, buffer, 65535);
	buffer[size] = '\0';
	i = 0;
	j = 0;
	w *= h;
	while (buffer[j])
	{
		(*map)[i / w][i % w] = buffer[j];
		printf("%c", (*map)[i / w][i % w]);
		if (buffer[j] != '\n')
			i++;
		j++;
	}
	close(fd);
}

