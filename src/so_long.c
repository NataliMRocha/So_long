/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/20 20:18:10 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// valgrind --leak-check=full --suppressions="erros.txt" --log-file="log.txt" ./so_long

int	main(int argc, const char *argv[])
{
	t_def *def;
	
	validation(&def, argc, argv[1]);
	init(&def);
	mlx_loop(def->mlx);
	close_game(&def, 1);
	return (EXIT_SUCCESS);
}
