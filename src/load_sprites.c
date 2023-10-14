/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:31:34 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/14 19:52:12 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init(t_def **def)
{
	// int32_t			w;
	// int32_t			h;
	// if (w > 1200)
	// 	w = 1200;
	// if (h > 600)
	// 	h = 600;
	(*def)->mlx = mlx_init(WIDTH, HEIGHT, "So_long", false);
	if(!(*def)-> mlx)
	{
		mlx_close_window((*def)->mlx);
		ft_close(def);
	}
	ft_load(def);
}

void ft_load(t_def **def)
{
	(*def)->sprites = malloc(sizeof(t_sprite));
	(*def)->sprites->bg = mlx_load_png("./sprites/bg/BG.png");
	(*def)->sprites->bg_1 = mlx_texture_to_image((*def)->mlx, (*def)->sprites->bg);
	(*def)->sprites->player = mlx_load_png("./sprites/player/Player_1.png");
	(*def)->sprites->player_1 = mlx_texture_to_image((*def)->mlx, (*def)->sprites->player);
	(*def)->sprites->wall = mlx_load_png("./sprites/wall/Wall.png");
	(*def)->sprites->wall_1 = mlx_texture_to_image((*def)->mlx, (*def)->sprites->wall);
	(*def)->sprites->collectible = mlx_load_png("./sprites/collectible/Collectible_1.png");
	(*def)->sprites->collectible_1 = mlx_texture_to_image((*def)->mlx, (*def)->sprites->collectible);
	(*def)->sprites->portal = mlx_load_png("./sprites/exit/Exit.png");
	(*def)->sprites->portal_1 = mlx_texture_to_image((*def)->mlx, (*def)->sprites->portal);
	
	mlx_image_to_window((*def)->mlx, (*def)->sprites->bg_1, 0, 0);
	mlx_image_to_window((*def)->mlx, (*def)->sprites->wall_1, 63, 424);
	mlx_image_to_window((*def)->mlx, (*def)->sprites->collectible_1, 500, 400);
	mlx_image_to_window((*def)->mlx, (*def)->sprites->player_1, 550, 400);
	mlx_image_to_window((*def)->mlx, (*def)->sprites->portal_1, 150, 150);
}
