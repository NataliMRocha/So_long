/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:57:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/24 18:30:26 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define WALL_SIZE 100
# define PLAYER_HEIGHT 64
# define PLAYER_WIDTH 60

typedef struct s_map	t_map;
struct					s_map
{
	char	**map;
	char	**copy;
	int		w;
	int		h;
	int		player;
	int		exitpoint;
	int		startpoint;
	int		collectable;
	int		enemy;
	int		x_init;
	int		y_init;
	int		collected;
	int		check_coin;
	int		exitable;
};

typedef struct s_sprite	t_sprite;
struct					s_sprite
{
	mlx_texture_t	*bg;
	mlx_image_t		*bg_1;
	mlx_texture_t	*player;
	mlx_image_t		*player_1;
	mlx_texture_t	*coin;
	mlx_image_t		*collectible_1;
	mlx_texture_t	*wall;
	mlx_image_t		*wall_1;
	mlx_texture_t	*portal;
	mlx_image_t		*portal_1;
	mlx_texture_t	*logo;
	mlx_image_t		*logo_1;
	mlx_texture_t	*enemy;
	mlx_image_t		*enemy_1;
};

typedef struct s_def	t_def;
struct					s_def
{
	mlx_t		*mlx;
	t_map		*map;
	t_sprite	*sprites;
	int			count_moves;
};

void	validation(t_def **def, int argc, const char *argv);
void	input_validation(int argc, const char *argv, t_def **def);
void	set_size(t_def **def);
void	create_matrix(t_def **def, const char *argv);
int		validate_map(t_def **def, int x, int y);
int		validate_map2(t_def **def);
void	init(t_def **def);
void	load(t_def **def);
void	get_position(t_def **def);
void	put_in_pos(char pos, t_def **def, int x, int y);
int		messages(int i);
int		move_y(t_def **def, size_t i);
int		move_x(t_def **def, size_t i);
void	close_game(t_def **def, int flag, int msg);
void	free_assets(t_def **def);
void	ft_free_validation(t_def **def, int i, int flag);
void	ft_hook(mlx_key_data_t keydata, t_def **def);
void	is_collectable(t_def **def);
void	end_game(t_def **def);
void	flood_fill(t_def **def, int x, int y);
void	display_msg(int msg, t_def **def);
int		is_enemy(t_def **def);

#endif