/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:57:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/14 20:08:35 by namoreir         ###   ########.fr       */
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
# define WIDTH 1200
# define HEIGHT 600


typedef struct s_map	t_map;
struct s_map{
	char	**buffer;
	char	**validate;
	int		w;
	int		h;
	int		x;
	int		y;
	int		player;
	int		exitpoint;
	int		startpoint;
	int		collectable;
	int		x_init;
	int		y_init;
	int		collected;
	bool	escapable;
};

typedef struct s_sprite	t_sprite;
struct s_sprite{
	mlx_texture_t *bg;
	mlx_image_t *bg_1;
	mlx_texture_t *player;
	mlx_image_t *player_1;
	mlx_texture_t *collectible;
	mlx_image_t *collectible_1;
	mlx_texture_t *wall;
	mlx_image_t *wall_1;
	mlx_texture_t *portal;
	mlx_image_t *portal_1;
};

typedef struct s_def	t_def;
struct s_def{
	mlx_t			*mlx;
	t_map			*map;
	t_sprite		*sprites;
};

void ft_player(void* param);
void	ft_hook(void *param);
void ft_load(t_def **def);
void read_map(t_def *def, char *path);
void ft_init(t_def **def);
void ft_close(t_def **def);
void	create_matrix(char ***map, char *path, int w, int h);
void	read_line(t_def **def, char *path);

#endif