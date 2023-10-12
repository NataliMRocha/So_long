/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:57:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/12 16:40:51 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_def	t_def;
struct s_def{
	mlx_t *mlx;
	mlx_image_t *image[5];
	mlx_texture_t *png[5];
};

void ft_player(void* param);
void ft_hook(void* param);
void ft_load(void* param);

#endif