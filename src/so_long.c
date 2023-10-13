/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/13 20:55:36 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	t_def	*pt;

	pt = param;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_UP) || mlx_is_key_down(pt->mlx,
			MLX_KEY_W))
		pt->image[1]->instances[0].y -= 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_DOWN) || mlx_is_key_down(pt->mlx,
			MLX_KEY_S))
		pt->image[1]->instances[0].y += 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_LEFT) || mlx_is_key_down(pt->mlx,
			MLX_KEY_A))
		pt->image[1]->instances[0].x -= 5;
	if (mlx_is_key_down(pt->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(pt->mlx,
			MLX_KEY_D))
		pt->image[1]->instances[0].x += 5;
}

static void	read_line(t_def **def, char *path)
{
	int		fd;
	int		size;
	int		i;
	char	buffer[1024];

	fd = open(path, O_RDONLY);
	size = read(fd, buffer, 1024);
	(*def)->map.w = 0;
	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			break ;
		(*def)->map.w++;
	}
	if ((*def)->map.w)
		(*def)->map.h = size / (*def)->map.w;
	close(fd);
}

void	create_matrix(char ***map, char *path, int w, int h)
{
	int		i;
	int		fd;
	int		j;
	int		size;
	char	buffer[65535];

	(*map) = (char **)malloc(h * sizeof(char *));
	i = -1;
	while (++i < h)
		(*map)[i] = (char *)malloc(w * sizeof(char));
	fd = open(path, O_RDONLY);
	size = read(fd, buffer, 65535);
	buffer[size] = '\0';
	i = 0;
	j = 0;
	while (buffer[j])
	{
		*map[i / h][i % h] = buffer[j];
		if (buffer[j] != '\n')
			i++;
		j++;
		// printf("%c", *map[i / w][i % w]);
	}
	close(fd);
}

int32_t	main(int32_t argc, const char *argv[])
{
	t_def *def;

	def = malloc(sizeof(t_def));
	read_line(&def, "./maps/valid_map_1.ber");
	create_matrix(&(def->map.buffer), "./maps/valid_map_1.ber", def->map.w - 1,
		def->map.h - 1);
	create_matrix(&(def->map.validate), "./maps/valid_map_1.ber", def->map.w - 1,
		def->map.h - 1);
	def->mlx = mlx_init(WIDTH, HEIGHT, "So_long", true);
	ft_load(def);
	mlx_loop_hook(def->mlx, ft_hook, def);
	mlx_loop(def->mlx);
	mlx_terminate(def->mlx);
	return (EXIT_SUCCESS);
}