/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/17 20:31:23 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// valgrind --leak-check=full --suppressions="erros.txt" --log-file="log.txt" ./so_long

int	main(int argc, const char *argv[])
{
	t_def *def;
	
	validate_map(argc, (char *)argv[1], &def);
	mlx_loop_hook(def->mlx, ft_hook, def);
	mlx_loop(def->mlx);
	ft_close(&def);
	free(def);
	return (EXIT_SUCCESS);
}