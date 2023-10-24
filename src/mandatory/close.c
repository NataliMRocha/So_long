/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:36:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/24 17:29:41 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_def **def, int flag, int msg)
{
	int	i;

	if (flag <= 2)
	{
		i = -1;
		while (++i < (*def)->map->h)
			free((*def)->map->buffer[i]);
		free((*def)->map->buffer);
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
}

void	display_msg(int msg, t_def **def)
{
	if (msg <= 11)
		messages(msg);
	if (msg == 12 && (*def)->sprites->portal_1->enabled == true)
		messages(msg);
}
