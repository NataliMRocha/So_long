/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/16 10:45:45 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int32_t argc, const char *argv[])
{
	t_def *def;
	int i = -1;

	def = calloc(1, sizeof(t_def));
	ft_init(&def);
	def->map = calloc(1, sizeof(t_map));
	read_line(&def, argv[1]);
	create_matrix(&def->map->buffer, argv[1], def->map->w - 1,
		def->map->h - 1);
	create_matrix(&def->map->validate, argv[1], def->map->w - 1,
		def->map->h - 1);
	mlx_loop_hook(def->mlx, ft_hook, def);
	mlx_loop(def->mlx);
	ft_close(&def);
	free(def);
	return (EXIT_SUCCESS);
}