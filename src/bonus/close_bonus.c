/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:36:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/24 20:11:07 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	close_game(t_def **def, int flag, int msg)
{
	int	i;

	if (flag <= 2)
	{
		i = -1;
		while (++i < (*def)->map->h)
			free((*def)->map->map[i]);
		free((*def)->map->map);
		i = -1;
		while (++i < (*def)->map->h)
			free((*def)->map->copy[i]);
		free((*def)->map->copy);
		free((*def)->map);
	}
	display_msg(msg, def);
	if (flag <= 1)
	{
		free_assets(def);
		free((*def)->sprites);
		mlx_terminate((*def)->mlx);
	}
	free((*def));
	return ;
}

void	free_assets(t_def **def)
{
	mlx_delete_image((*def)->mlx, (*def)->sprites->bg_1);
	mlx_delete_texture((*def)->sprites->bg);
	mlx_delete_image((*def)->mlx, (*def)->sprites->player_1);
	mlx_delete_texture((*def)->sprites->player);
	mlx_delete_image((*def)->mlx, (*def)->sprites->collectible_1);
	mlx_delete_texture((*def)->sprites->coin);
	mlx_delete_image((*def)->mlx, (*def)->sprites->wall_1);
	mlx_delete_texture((*def)->sprites->wall);
	mlx_delete_image((*def)->mlx, (*def)->sprites->portal_1);
	mlx_delete_texture((*def)->sprites->portal);
	mlx_delete_texture((*def)->sprites->logo);
	mlx_delete_image((*def)->mlx, (*def)->sprites->enemy_1);
	mlx_delete_texture((*def)->sprites->enemy);
}

void	display_msg(int msg, t_def **def)
{
	if (msg <= 11)
		messages(msg);
	if (msg == 12 && (*def)->sprites->portal_1->enabled == true)
		messages(msg);
	if (msg == 13)
		messages(msg);
}

void	end_game(t_def **def)
{
	int	x_player;
	int	y_player;
	int	x_exit;
	int	y_exit;

	x_player = (*def)->sprites->player_1->instances->x;
	y_player = (*def)->sprites->player_1->instances->y;
	x_exit = (*def)->sprites->portal_1->instances->x;
	y_exit = (*def)->sprites->portal_1->instances->y;
	if ((*def)->map->collected == (*def)->map->collectable
		&& (*def)->sprites->portal_1->enabled == false)
		(*def)->sprites->portal_1->enabled = true;
	if ((x_player > x_exit && x_player < (x_exit + 100)) && (y_player > y_exit
			&& y_player < (y_exit + 100))
		&& (*def)->sprites->portal_1->enabled == true)
		return (mlx_close_window((*def)->mlx));
}
