/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/12 16:50:22 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_hook(void* param)
{
	t_def *pt = param;

	if (mlx_is_key_down(pt->mlx, MLX_KEY_UP) || mlx_is_key_down(pt->mlx, MLX_KEY_W))
		pt->image[1]->instances[0].y -= 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_DOWN) || mlx_is_key_down(pt->mlx, MLX_KEY_S))
		pt->image[1]->instances[0].y += 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_LEFT) || mlx_is_key_down(pt->mlx, MLX_KEY_A))
		pt->image[1]->instances[0].x -= 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(pt->mlx, MLX_KEY_D))
		pt->image[1]->instances[0].x += 5;
	// printf("%d\n", pt->image[1]->instances[0].x);
		
}

int32_t main(int32_t argc, const char* argv[])
{
	t_def *def;
		
	def = malloc(sizeof(t_def));
	def->mlx = mlx_init(WIDTH, HEIGHT, "So_long", true);
	ft_load(def);
	mlx_loop_hook(def->mlx, ft_hook, def);
	mlx_loop(def->mlx);
	mlx_terminate(def->mlx);
	return (EXIT_SUCCESS);
}
