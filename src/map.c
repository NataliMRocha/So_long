/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:59:30 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/20 16:48:06 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_map(t_def **def, int x, int y)
{
	while(y < (*def)->map->h)
	{
		x = 0;
		while(x < (*def)->map->w)
		{
			if((*def)->map->buffer[y][0] != '1' || (*def)->map->buffer[0][x] != '1'
				|| (*def)->map->buffer[y][(*def)->map->w - 1] != '1' ||
				(*def)->map->buffer[(*def)->map->h - 1][x] != '1' ||
				ft_strchr("EPC10", (*def)->map->buffer[y][x]) == NULL)
				return(1);
			if((*def)->map->buffer[y][x] == 'P')
			{
				(*def)->map->player++;
				(*def)->map->x_init = x;
				(*def)->map->y_init = y;
			}
			else if ((*def)->map->buffer[y][x]== 'E')
				(*def)->map->exitpoint++;
			else if ((*def)->map->buffer[y][x] == 'C')
				(*def)->map->collectable++;
			x++;
		}
		y++;
	}
	return(0);
}

int validate_map2(t_def **def)
{
	if((*def)->map->player != 1)
		return(6);
	if((*def)->map->exitpoint != 1)
		return(7);
	if((*def)->map->collectable < 1)
		return(8);
	if ((*def)->map->w == (*def)->map->h)
		return(9);
	return(0);
}