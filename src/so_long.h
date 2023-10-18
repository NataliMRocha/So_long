/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:57:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/17 21:20:23 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 1400
# define HEIGHT 700
# define BUFFER_SIZE 32000

typedef struct s_map	t_map;
struct					s_map
{
	char	**buffer;
	char	**validate;
	int		w;
	int		h;
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
struct					s_sprite
{
	mlx_texture_t	*bg;
	mlx_image_t		*bg_1;
	mlx_texture_t	*player;
	mlx_image_t		*player_1;
	mlx_texture_t	*collectible;
	mlx_image_t		*collectible_1;
	mlx_texture_t	*wall;
	mlx_image_t		*wall_1;
	mlx_texture_t	*portal;
	mlx_image_t		*portal_1;
};

typedef struct s_def	t_def;
struct					s_def
{
	mlx_t		*mlx;
	t_map		*map;
	t_sprite	*sprites;
};

void	validate_map(int argc, const char *argv, t_def **def);
int		validate_map2(t_def **def, int x, int y);
int		messages(int i);
void	ft_player(void *param);
void	ft_hook(void *param);
void	ft_load(t_def **def);
void	read_map(t_def *def, char *path);
void	ft_init(t_def **def);
void	ft_close(t_def **def);
void	create_matrix(t_def **def, const char *argv, char flag);
void	read_line(t_def **def, const char *argv);
void	get_position(t_def **def);
void	put_in_pos(char pos, t_def **def, int x, int y);

#endif