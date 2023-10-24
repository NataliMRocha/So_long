/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:58:47 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/24 20:11:29 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_hook(mlx_key_data_t keydata, t_def **def)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window((*def)->mlx);
		close_game(def, 1, 11);
		exit(12);
	}
	else if (((keydata.key == MLX_KEY_UP) || (keydata.key == MLX_KEY_W))
		&& keydata.action == MLX_PRESS && move_y(def, 1))
		(*def)->sprites->player_1->instances->y -= 100;
	else if (((keydata.key == MLX_KEY_DOWN) || (keydata.key == MLX_KEY_S))
		&& keydata.action == MLX_PRESS && move_y(def, 2))
		(*def)->sprites->player_1->instances->y += 100;
	else if (((keydata.key == MLX_KEY_LEFT) || (keydata.key == MLX_KEY_A))
		&& keydata.action == MLX_PRESS && move_x(def, 1))
		(*def)->sprites->player_1->instances->x -= 100;
	else if (((keydata.key == MLX_KEY_RIGHT) || (keydata.key == MLX_KEY_D))
		&& keydata.action == MLX_PRESS && move_x(def, 2))
		(*def)->sprites->player_1->instances->x += 100;
	is_collectable(def);
	is_enemy(def);
	end_game(def);
}

int	move_y(t_def **def, size_t i)
{
	int	x_player;
	int	y_player;
	int	x_wall;
	int	y_wall;

	x_player = (*def)->sprites->player_1->instances->x;
	if (i == 1)
		y_player = (*def)->sprites->player_1->instances->y - WALL_SIZE;
	else
		y_player = (*def)->sprites->player_1->instances->y + WALL_SIZE;
	i = 0;
	while (i < (*def)->sprites->wall_1->count)
	{
		x_wall = (*def)->sprites->wall_1->instances[i].x;
		y_wall = (*def)->sprites->wall_1->instances[i].y;
		if ((x_player > x_wall && x_player < (x_wall + 100))
			&& (y_player > y_wall && y_player < (y_wall + 100)))
			return (false);
		i++;
	}
	(*def)->count_moves++;
	ft_printf("Moves: %d\n", (*def)->count_moves);
	return (true);
}

int	move_x(t_def **def, size_t i)
{
	int	x_player;
	int	y_player;
	int	x_wall;
	int	y_wall;

	y_player = (*def)->sprites->player_1->instances->y;
	if (i == 2)
		x_player = (*def)->sprites->player_1->instances->x + WALL_SIZE;
	else
		x_player = (*def)->sprites->player_1->instances->x - WALL_SIZE;
	i = 0;
	while (i < (*def)->sprites->wall_1->count)
	{
		x_wall = (*def)->sprites->wall_1->instances[i].x;
		y_wall = (*def)->sprites->wall_1->instances[i].y;
		if ((x_player > x_wall && x_player < (x_wall + 100))
			&& (y_player > y_wall && y_player < (y_wall + 100)))
			return (false);
		i++;
	}
	(*def)->count_moves++;
	ft_printf("Moves: %d\n", (*def)->count_moves);
	return (true);
}

void	is_collectable(t_def **def)
{
	int	x_player;
	int	y_player;
	int	x_collectable;
	int	y_collectable;
	int	i;

	x_player = (*def)->sprites->player_1->instances->x;
	y_player = (*def)->sprites->player_1->instances->y;
	i = -1;
	while (++i < (*def)->map->collectable)
	{
		x_collectable = (*def)->sprites->collectible_1->instances[i].x;
		y_collectable = (*def)->sprites->collectible_1->instances[i].y;
		if (x_player < x_collectable && (x_player
				+ PLAYER_WIDTH) > (x_collectable + 25)
			&& y_player < y_collectable && (y_player
				+ PLAYER_HEIGHT) > y_collectable + 38
			&& (*def)->sprites->collectible_1->instances[i].enabled == true)
		{
			(*def)->map->collected++;
			(*def)->sprites->collectible_1->instances[i].enabled = false;
			return ;
		}
	}
}

int	is_enemy(t_def **def)
{
	int	x_player;
	int	y_player;
	int	x_enemy;
	int	y_enemy;
	int	i;

	x_player = (*def)->sprites->player_1->instances->x;
	y_player = (*def)->sprites->player_1->instances->y;
	i = -1;
	while (++i < (*def)->map->enemy)
	{
		x_enemy = (*def)->sprites->enemy_1->instances[i].x;
		y_enemy = (*def)->sprites->enemy_1->instances[i].y;
		if (x_player < x_enemy && (x_player + PLAYER_WIDTH) > (x_enemy + 50)
			&& y_player < y_enemy
			&& (y_player + PLAYER_HEIGHT) > (y_enemy + 50))
		{
			close_game(def, 1, 13);
			exit(13);
		}
	}
	return (true);
}
