/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/14 20:17:06 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int32_t argc, const char *argv[])
{
	t_def *def;

	// def = malloc(sizeof(t_def));
	def = calloc(1, sizeof(t_def));
	ft_init(&def);
	def->map = calloc(1, sizeof(t_map));
	read_line(&def, "./maps/valid_map_1.ber");
	create_matrix(&(def->map->buffer), "./maps/valid_map_1.ber", def->map->w - 1,
		def->map->h - 1);
	create_matrix(&(def->map->validate), "./maps/valid_map_1.ber", def->map->w - 1,
		def->map->h - 1);
	mlx_loop_hook(def->mlx, ft_hook, def);
	mlx_loop(def->mlx);
	ft_close(&def);
	free(def);
	return (EXIT_SUCCESS);
}