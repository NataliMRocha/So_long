/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:57:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/13 18:44:55 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "../MLX42/include/MLX42/MLX42.h"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map	t_map;
struct s_map{
	char	**buffer;
	char	**validate;
	int		collectable;
	int		exitpoint;
	int		startpoint;
	int		w;
	int		h;
};

typedef struct s_def	t_def;
struct s_def{
	mlx_t *mlx;
	mlx_image_t *image[5];
	mlx_texture_t *png[5];
	t_map map;
	
};

void ft_player(void* param);
void ft_hook(void* param);
void ft_load(void* param);
void read_map(t_def *def, char *path);

#endif