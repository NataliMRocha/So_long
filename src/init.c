/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:31:34 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/23 16:19:46 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_def **def)
{
	int	width;
	int	height;

	width = (*def)->map->w * WALL_SIZE;
	height = (*def)->map->h * WALL_SIZE;
	if (width > 1700)
		width = 1700;
	if (height > 900)
		height = 900;
	(*def)->mlx = mlx_init(width, height, "So_long", false);
	if (!(*def)->mlx)
	{
		mlx_close_window((*def)->mlx);
		close_game(def, 1, 10);
	}
	load(def);
	get_position(def);
	mlx_key_hook((*def)->mlx, (void *)ft_hook, (void *)def);
}

void	load(t_def **def)
{
	(*def)->sprites = ft_calloc(1, sizeof(t_sprite));
	(*def)->sprites->bg = mlx_load_png("./sprites/bg/BG.png");
	(*def)->sprites->bg_1 = mlx_texture_to_image((*def)->mlx,
			(*def)->sprites->bg);
	(*def)->sprites->player = mlx_load_png("./sprites/player/Player_1.png");
	(*def)->sprites->player_1 = mlx_texture_to_image((*def)->mlx,
			(*def)->sprites->player);
	(*def)->sprites->wall = mlx_load_png("./sprites/wall/Wall.png");
	(*def)->sprites->wall_1 = mlx_texture_to_image((*def)->mlx,
			(*def)->sprites->wall);
	(*def)->sprites->coin = mlx_load_png("./sprites/collectible/coin.png");
	(*def)->sprites->collectible_1 = mlx_texture_to_image((*def)->mlx,
			(*def)->sprites->coin);
	(*def)->sprites->portal = mlx_load_png("./sprites/exit/Exit.png");
	(*def)->sprites->portal_1 = mlx_texture_to_image((*def)->mlx,
			(*def)->sprites->portal);
	(*def)->sprites->logo = mlx_load_png("./sprites/player/Player_1.png");
	mlx_set_icon((*def)->mlx, (*def)->sprites->logo);
	mlx_image_to_window((*def)->mlx, (*def)->sprites->bg_1, 0, 0);
}

void	get_position(t_def **def)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*def)->map->h * WALL_SIZE)
	{
		y = 0;
		while (y < (*def)->map->w * WALL_SIZE)
		{
			put_in_pos((*def)->map->buffer[x / WALL_SIZE][y / WALL_SIZE], \
								def, y, x);
			y += WALL_SIZE;
		}
		x += WALL_SIZE;
	}
}

void	put_in_pos(char pos, t_def **def, int x, int y)
{
	if (pos == '1')
		mlx_image_to_window((*def)->mlx, (*def)->sprites->wall_1, x, y);
	if (pos == 'C')
		mlx_image_to_window((*def)->mlx,
			(*def)->sprites->collectible_1, x + 30, y + 30);
	if (pos == 'E')
	{
		mlx_image_to_window((*def)->mlx, (*def)->sprites->portal_1, x, y);
		(*def)->sprites->portal_1->enabled = false;
	}
	if (pos == 'P')
		mlx_image_to_window((*def)->mlx,
			(*def)->sprites->player_1, x + 15, y + 10);
}
