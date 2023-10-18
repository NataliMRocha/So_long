/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:59:30 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/17 21:23:40 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	validate_map(int argc, const char *argv, t_def **def)
{
	int	i;

	if(argc != 2)
		exit(messages(1));
	i = ft_strlen(argv);
	if (ft_strncmp(&argv[i - 4], ".ber", 4) != 0)
		exit(messages(3));
	(*def) = ft_calloc(1, sizeof(t_def));
	read_line(&(*def), argv);
	create_matrix(def, argv, 'b');
	create_matrix(def, argv, 'v');
	i = validate_map2(def, 0, 0);
	
	ft_init(def);
	get_position(def);
}

int validate_map2(t_def **def, int x, int y)
{
	while(y < (*def)->map->h)
	{
		x = 0;
		while(x < (*def)->map->w)
		{
			if((*def)->map->buffer[y][0] != '1' || (*def)->map->buffer[0][x] != '1'
				|| (*def)->map->buffer[y][(*def)->map->w - 1] != '1' ||
				(*def)->map->buffer[(*def)->map->h - 1][x] != '1' ||
				ft_strchr("10CPE", (*def)->map->buffer[y][x]) == NULL)
				return(MLX_INVFILE);
			if((*def)->map->buffer[y][x] == 'P')
			{
				(*def)->map->player++;
				(*def)->map->x_init = y;
				(*def)->map->y_init = x;
			}
			else if ((*def)->map->buffer[y][x]=='E')
				(*def)->map->exitpoint++;
			else if ((*def)->map->buffer[y][x] == 'C')
				(*def)->map->collectable++;
			x++;
		}
		y++;
	}
	return(MLX_SUCCESS);
}

void	read_line(t_def **def, const char *argv)
{
	int		fd;
	int		size;
	int		i;
	char	buffer[BUFFER_SIZE];

	fd = open(argv, O_RDONLY);
	size = read(fd, buffer, BUFFER_SIZE);
	if(!size)
		return ;
	(*def)->map = ft_calloc(1, sizeof(t_map));
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
	i = 0;
	close(fd);
}

void	create_matrix(t_def **def, const char *argv, char flag)
{
	int		i;
	int		j;
	int		fd;
	char	buff[BUFFER_SIZE];
	
	fd = open(argv, O_RDONLY);
	j = read(fd, buff, BUFFER_SIZE);
	buff[j] = '\0';
	if (flag == 'v')
		(*def)->map->validate = ft_split(buff, '\n');
	else
		(*def)->map->buffer = ft_split(buff, '\n');
	close(fd);
	(*def)->map->player = 0;
	(*def)->map->collectable = 0;
	(*def)->map->exitpoint = 0;
}

void	get_position(t_def **def)
{
	int x;
	int y;
	int col;

	col = 0;
	x = 0;
	y = 0;
	while(x < (*def)->map->h * 100)
	{
		y = 0;
		while(y < (*def)->map->w * 100)
		{
			put_in_pos((*def)->map->buffer[x / 100][y / 100], \
								def, y, x);
			y += 100;
		}
		x += 100;
	}
}

void	put_in_pos(char pos, t_def **def, int x, int y)
{
	if (pos == '1')
		mlx_image_to_window((*def)->mlx, (*def)->sprites->wall_1, x, y);
	if (pos == 'C')
		mlx_image_to_window((*def)->mlx, (*def)->sprites->collectible_1, x, y);
	if (pos == 'E')
		mlx_image_to_window((*def)->mlx, (*def)->sprites->portal_1, x, y);
	if (pos == 'P')
		mlx_image_to_window((*def)->mlx, (*def)->sprites->player_1, x, y);
}
