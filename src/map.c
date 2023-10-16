/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:59:30 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/16 17:39:22 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	read_line(t_def **def, const char *argv)
{
	int		fd;
	int		size;
	int		i;
	char	buffer[BUFFER_SIZE];

	fd = open(argv, O_RDONLY);
	size = read(fd, buffer, BUFFER_SIZE);
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

void	create_matrix(t_def **def, const char *argv, int w, int h)
{
	int		i;
	int		j;
	int		fd;
	int		size;
	char	buffer[BUFFER_SIZE];

	(*def)->map->buffer = (char **)calloc(h + 1, sizeof(char *));
	i = -1;
	while (++i < h)
		(*def)->map->buffer[i] = (char *)calloc(w + 1, sizeof(char));
	fd = open(argv, O_RDONLY);
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = '\0';
	i = 0;
	j = 0;
	while (buffer[j])
	{
		(*def)->map->buffer[i / w][i % w] = buffer[j];
		if (buffer[j] != '\n')
			i++;
		j++;
	}
	close(fd);
}

void	map_to_window(t_def **def)
{
	int x;
	int y;
	int line = 0;
	int col = 0;
	
	x = 0;
	y = 0;
	while(x < (*def)->map->h * 100)
	{
		y = 0;
		line = 0;
		while(y < (*def)->map->w * 100)
		{
			if ((*def)->map->buffer[col][line] == '1')
				mlx_image_to_window((*def)->mlx, (*def)->sprites->wall_1, y, x);
			if ((*def)->map->buffer[col][line] == 'P')
				mlx_image_to_window((*def)->mlx, (*def)->sprites->player_1, y, x);
			if ((*def)->map->buffer[col][line] == 'C')
				mlx_image_to_window((*def)->mlx, (*def)->sprites->collectible_1, y, x);
			if ((*def)->map->buffer[col][line] == 'E')
				mlx_image_to_window((*def)->mlx, (*def)->sprites->portal_1, y, x);
			y += 100;
			line++;
		}
		x += 100;
		col++;
	}
}