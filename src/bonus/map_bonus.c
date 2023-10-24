/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:59:30 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/24 18:27:49 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	validate_map(t_def **def, int x, int y)
{
	while (++y < (*def)->map->h)
	{
		x = -1;
		while (++x < (*def)->map->w)
		{
			if ((*def)->map->map[y][0] != '1' || (*def)->map->map[0][x] != '1'
				|| (*def)->map->map[y][(*def)->map->w - 1] != '1'
				|| (*def)->map->map[(*def)->map->h - 1][x] != '1'
				|| ft_strchr("EPC10D", (*def)->map->map[y][x]) == NULL)
				return (5);
			if ((*def)->map->map[y][x] == 'P')
			{
				(*def)->map->player++;
				(*def)->map->x_init = y;
				(*def)->map->y_init = x;
			}
			else if ((*def)->map->map[y][x] == 'E')
				(*def)->map->exitpoint++;
			else if ((*def)->map->map[y][x] == 'C')
				(*def)->map->collectable++;
		}
	}
	return (0);
}

int	validate_map2(t_def **def)
{
	if ((*def)->map->player != 1)
		return (6);
	if ((*def)->map->exitpoint != 1)
		return (7);
	if ((*def)->map->collectable < 1)
		return (8);
	if ((*def)->map->w == (*def)->map->h)
		return (9);
	return (0);
}

void	flood_fill(t_def **def, int x, int y)
{
	if (x >= 0 && y >= 0 && x < (*def)->map->h && y < (*def)->map->w)
	{
		if ((*def)->map->copy[x][y] == '1' || (*def)->map->copy[x][y] == 'x'
			|| (*def)->map->copy[x][y] == 'p' || (*def)->map->copy[x][y] == 'e')
			return ;
		else if ((*def)->map->copy[x][y] == 'C' && (*def)->map->check_coin++)
			(*def)->map->copy[x][y] = '0';
		else if ((*def)->map->copy[x][y] == '0')
			(*def)->map->copy[x][y] = 'x';
		else if ((*def)->map->copy[x][y] == 'P')
			(*def)->map->copy[x][y] = 'p';
		else if ((*def)->map->copy[x][y] == 'E')
		{
			(*def)->map->exitable = 1;
			(*def)->map->copy[x][y] = 'e';
		}
		else if ((*def)->map->copy[x][y] == 'D')
			(*def)->map->copy[x][y] = '1';
		flood_fill(def, x + 1, y);
		flood_fill(def, x - 1, y);
		flood_fill(def, x, y + 1);
		flood_fill(def, x, y - 1);
	}
}
