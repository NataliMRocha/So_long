/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:31:34 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/12 16:52:52 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_load(void* param)
{
	t_def *def;
	
	// def =(t_def *)malloc(sizeof(t_def));
	def = param;
	def->png[0] = mlx_load_png("./sprites/BG.png");
	def->image[0] = mlx_texture_to_image(def->mlx, def->png[0]);
	def->png[1] = mlx_load_png("./sprites/Player_1.png");
	def->image[1] = mlx_texture_to_image(def->mlx, def->png[1]);
	def->png[2] = mlx_load_png("./sprites/parede.png");
	def->image[2] = mlx_texture_to_image(def->mlx, def->png[2]);
	// def->png[3] = mlx_load_png("./sprites/Collectible_1.png");
	// def->image[3] = mlx_texture_to_image(def->mlx, def->png[3]);
	// def->png[4] = mlx_load_png("./sprites/Exit.png");
	// def->image[4] = mlx_texture_to_image(def->mlx, def->png[4]);

	mlx_image_to_window(def->mlx, def->image[0], 0, 0);
	mlx_image_to_window(def->mlx, def->image[1], 100, 100);
	mlx_image_to_window(def->mlx, def->image[2], 150, 150);
	mlx_image_to_window(def->mlx, def->image[2], 150, 200);
	mlx_image_to_window(def->mlx, def->image[2], 150, 250);
	// mlx_image_to_window(def->mlx, def->image[3], 100, 100);
	// mlx_image_to_window(def->mlx, def->image[4], 100, 100);
}
