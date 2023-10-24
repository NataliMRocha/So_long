/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:45:17 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/23 16:56:47 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*get_char_node(char c)
{
	t_liste	*set;

	set = (t_liste *)malloc(sizeof(t_liste));
	set->char_read = c;
	set->next = NULL;
	return (set);
}

void	put_in_pos_gnl(t_liste **lst, t_liste *new)
{
	t_liste	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

char	*free_file(t_liste *line)
{
	t_liste	*temp;

	temp = line;
	while (temp)
	{
		temp = temp->next;
		free(line);
		line = temp;
	}
	temp = NULL;
	return (NULL);
}
