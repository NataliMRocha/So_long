/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:32 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/06 17:36:15 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_load(void* param)
{
	t_def *def;
	
	def = param;
	def->png[1] = mlx_load_png("./sprites/player1.png");
	def->image[1] = mlx_texture_to_image(def->mlx, def->png[1]);
	def->png[2] = mlx_load_png("./sprites/player2.png");
	def->image[2] = mlx_texture_to_image(def->mlx, def->png[2]);
	def->png[3] = mlx_load_png("./sprites/player3.png");
	def->image[3] = mlx_texture_to_image(def->mlx, def->png[3]);
	def->png[4] = mlx_load_png("./sprites/player4.png");
	def->image[4] = mlx_texture_to_image(def->mlx, def->png[4]);
	mlx_image_to_window(def->mlx, def->image[1], 100, 100);
	mlx_image_to_window(def->mlx, def->image[2], 100, 100);
	mlx_image_to_window(def->mlx, def->image[3], 100, 100);
	mlx_image_to_window(def->mlx, def->image[4], 100, 100);
}
void ft_place(void* param)
{
	t_def *def;
	
	def = param;
	def->image[2] = def->image[1]->enabled = 0;
	def->image[3] = def->image[2]->enabled = 0;
	def->image[4] = def->image[3]->enabled = 0;
	if (def->image[4]->enabled)
	{	
		def->image[4]->enabled = 0;
		def->image[1]-> enabled;
	}
	
}