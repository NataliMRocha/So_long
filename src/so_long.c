/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/06 17:37:48 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_hook(void* param)
{
	t_def *pt = param;

	if (mlx_is_key_down(pt->mlx, MLX_KEY_UP))
		pt->image[1]->instances[0].y -= 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_DOWN))
		pt->image[1]->instances[0].y += 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_LEFT))
		pt->image[1]->instances[0].x -= 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_RIGHT))
		pt->image[1]->instances[0].x += 5;
		// printf("%d\n", pt->image[1]->instances[0].x);
		
}

int32_t main(int32_t argc, const char* argv[])
{
	t_def *def;
		
	def = malloc(sizeof(t_def));
	def->mlx = mlx_init(WIDTH, HEIGHT, "So_long", true);
	def->png[0] = mlx_load_png("./sprites/Background.png");
	def->image[0] = mlx_texture_to_image(def->mlx, def->png[0]);
	def->png[1] = mlx_load_png("./sprites/player1.png");
	def->image[1] = mlx_texture_to_image(def->mlx, def->png[1]);
	mlx_image_to_window(def->mlx, def->image[1], 100, 100);
	mlx_image_to_window(def->mlx, def->image[0], 0, 0);
	mlx_loop_hook(def->mlx, ft_hook, def);
	// mlx_loop_hook(def->mlx, ft_player, def->mlx);
	mlx_loop(def->mlx);
	mlx_terminate(def->mlx);
	return (EXIT_SUCCESS);

}
