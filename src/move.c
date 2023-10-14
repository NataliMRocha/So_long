/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:58:47 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/14 20:00:57 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	t_def *def;

	def = param;
	if (mlx_is_key_down((def)->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window((def)->mlx);
		return;
	}
	if (mlx_is_key_down((def)->mlx, MLX_KEY_UP) || mlx_is_key_down((def)->mlx,
			MLX_KEY_W))
		(def)->sprites->player_1->instances[0].y -= 5;
	if (mlx_is_key_down((def)->mlx, MLX_KEY_DOWN) || mlx_is_key_down((def)->mlx,
			MLX_KEY_S))
		(def)->sprites->player_1->instances[0].y += 5;
	if (mlx_is_key_down((def)->mlx, MLX_KEY_LEFT) || mlx_is_key_down((def)->mlx,
			MLX_KEY_A))
		(def)->sprites->player_1->instances[0].x -= 5;
	if (mlx_is_key_down((def)->mlx, MLX_KEY_RIGHT) || mlx_is_key_down((def)->mlx,
			MLX_KEY_D))
		(def)->sprites->player_1->instances[0].x += 5;
}

// void	ft_action_(t_def **def)
// {
	
// }