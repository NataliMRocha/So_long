/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/23 16:17:44 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, const char *argv[])
{
	t_def	*def;

	validation(&def, argc, argv[1]);
	init(&def);
	mlx_loop(def->mlx);
	return (EXIT_SUCCESS);
}
