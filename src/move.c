/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:58:47 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/20 20:17:15 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, t_def **def)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window((*def)->mlx);
		return;
	}
	else if ((keydata.key == MLX_KEY_UP) || (keydata.key == MLX_KEY_W) && 
		keydata.action == MLX_PRESS && move_y(def, 1))
		(*def)->sprites->player_1->instances->y -= 10;
	else if ((keydata.key == MLX_KEY_DOWN) || (keydata.key == MLX_KEY_S) && 
		keydata.action == MLX_PRESS && move_y(def, 2))
		(*def)->sprites->player_1->instances->y += 10;
	else if ((keydata.key == MLX_KEY_LEFT) || (keydata.key == MLX_KEY_A) &&
		keydata.action == MLX_PRESS && move_x(def, 1))
		(*def)->sprites->player_1->instances->x -= 10;
	else if ((keydata.key == MLX_KEY_RIGHT) || (keydata.key == MLX_KEY_D) &&
		keydata.action == MLX_PRESS && move_x(def, 2))
		(*def)->sprites->player_1->instances->x += 10;
}

int	move_y(t_def **def, int i)
{
	int	x_player;
	int	y_player;
	int	x_wall;
	int	y_wall;
	
	x_player = (*def)->sprites->player_1->instances->x;
	if (i == 1)
		y_player = (*def)->sprites->player_1->instances->y - PLAYER_HEIGHT;
	else
		y_player = (*def)->sprites->player_1->instances->y + PLAYER_HEIGHT;
	i = 0;
	while(i < (*def)->sprites->wall_1->count)
	{
		x_wall = (*def)->sprites->wall_1->instances[i].x;
		y_wall = (*def)->sprites->wall_1->instances[i].y;
		if ((x_player > x_wall && x_player < (x_wall + 100)) &&
			(y_player > y_wall && y_player < (y_player + 100)))
			return (false);
		i++;
	}
	(*def)->count_moves++;
	ft_printf("Moves: %d\n", (*def)->count_moves);
	return(true);
}

int	move_x(t_def **def, int i)
 {
	int	x_player;
	int	y_player;
	int	x_wall;
	int	y_wall;
	
	y_player = (*def)->sprites->player_1->instances->y;
	if (i == 2)
		x_player = (*def)->sprites->player_1->instances->x + 70;
	else
		x_player = (*def)->sprites->player_1->instances->x - 70;
	i = 0;
	while(i < (*def)->sprites->wall_1->count)
	{
		x_wall = (*def)->sprites->wall_1->instances[i].x;
		y_wall = (*def)->sprites->wall_1->instances[i].y;
		if ((x_player > x_wall && x_player < x_wall + 100) &&
			(y_player > y_wall && y_player < y_wall + 100))
			return (false);
		i++;
	}
	(*def)->count_moves++;
	ft_printf("Moves: %d\n", (*def)->count_moves);
	return(true);
 }