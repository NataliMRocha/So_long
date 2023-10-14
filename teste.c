/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:59:30 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/14 16:19:21 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
		*map[i / w][i % w] = buffer[j];
		if (buffer[j] != '\n')
			i++;
		j++;
		printf("%c", *map[i / w][i % w]);
	}
	close(fd);
}

	// read_line(&def, "./maps/valid_map_1.ber");
	// create_matrix(&(def->map.buffer), "./maps/valid_map_1.ber", def->map.w - 1,
	// 	def->map.h - 1);
	// create_matrix(&(def->map.validate), "./maps/valid_map_1.ber", def->map.w - 1,
	// 	def->map.h - 1);