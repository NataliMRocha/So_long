/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:36:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/16 10:47:37 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_close(t_def **def)
{
	int i = -1;
	
	mlx_delete_image((*def)->mlx, (*def)->sprites->bg_1);
	mlx_delete_texture((*def)->sprites->bg);
	mlx_delete_image((*def)->mlx, (*def)->sprites->player_1);
	mlx_delete_texture((*def)->sprites->player);
	mlx_delete_image((*def)->mlx, (*def)->sprites->collectible_1);
	mlx_delete_texture((*def)->sprites->collectible);
	mlx_delete_image((*def)->mlx, (*def)->sprites->wall_1);
	mlx_delete_texture((*def)->sprites->wall);
	mlx_delete_image((*def)->mlx, (*def)->sprites->portal_1);
	mlx_delete_texture((*def)->sprites->portal);
	while(++i < (*def)->map->h)
		free((*def)->map->buffer[i]);
	free((*def)->map->buffer);
	i = -1;
	while(++i < (*def)->map->h)
		free((*def)->map->validate[i]);
	free((*def)->map->validate);
	mlx_terminate((*def)->mlx);
	free((*def)->sprites);
	free((*def)->map);
}
