/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:36:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/17 20:40:21 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_close(t_def **def)
{
	int	i;

	i = -1;
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
	while (++i < (*def)->map->h)
		free((*def)->map->buffer[i]);
	free((*def)->map->buffer);
	i = -1;
	while(++i < (*def)->map->h)
		free((*def)->map->validate[i]);
	free((*def)->map->validate);
	free((*def)->map);
	free((*def)->sprites);
	mlx_terminate((*def)->mlx);
}

int	messages(int i)
{
	const char	*message[5] = {
		"Let's go to the desert!",
		"Please provide one and only one argument.\n"
		"It should be something like: \"./so_long map.ber\"",
		"This file isn't valid.\n Make sure it's a file with '.ber' extension.\n",
	};

	printf("%s", message[i]);
	return (i);
}
