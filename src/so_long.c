/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/24 12:20:55 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, const char *argv[])
{
	t_def	*def;

	validation(&def, argc, argv[1]);
	init(&def);
	mlx_key_hook(def->mlx, (void *)ft_hook, &def);
	mlx_loop(def->mlx);
	close_game(&def, 1, 11);
	return (EXIT_SUCCESS);
}
