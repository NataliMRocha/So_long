/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/16 16:41:10 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// valgrind --leak-check=full --suppressions="erros.txt" --log-file="log.txt" ./so_long

int32_t	main(int32_t argc, const char *argv[])
{
	t_def *def;
	int i = -1;

	def = calloc(1, sizeof(t_def));
	ft_init(&def);
	def->map = calloc(1, sizeof(t_map));
	read_line(&def, argv[1]);
	create_matrix(&def, argv[1], def->map->w,
		def->map->h);
	// create_matrix(&def->map->validate, argv[1], def->map->w - 1,
	// 	def->map->h - 1);
	map_to_window(&def);
	mlx_loop_hook(def->mlx, ft_hook, def);
	mlx_loop(def->mlx);
	ft_close(&def);
	free(def);
	return (EXIT_SUCCESS);
}