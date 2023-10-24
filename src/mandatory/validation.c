/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:59:42 by natali            #+#    #+#             */
/*   Updated: 2023/10/24 17:30:13 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validation(t_def **def, int argc, const char *argv)
{
	int	i;

	input_validation(argc, argv, def);
	i = validate_map(def, 0, 0);
	if (i != 0)
	{
		close_game(def, 2, i);
		exit(i);
	}
	i = validate_map2(def);
	if (i != 0)
	{
		close_game(def, 2, i);
		exit(i);
	}
	(*def)->map->check_coin = 0;
	(*def)->map->exitable = 0;
	flood_fill(def, (*def)->map->x_init, (*def)->map->y_init);
	if (((*def)->map->check_coin != (*def)->map->collectable)
		|| (*def)->map->exitable == 0 || (*def)->map->h == (*def)->map->w)
	{
		close_game(def, 2, 5);
		exit(5);
	}
}

void	input_validation(int argc, const char *argv, t_def **def)
{
	if (argc != 2)
		exit(messages(1));
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4) != 0)
		exit(messages(2));
	(*def) = ft_calloc(1, sizeof(t_def));
	if ((*def) == NULL)
		exit(messages(0));
	(*def)->map = ft_calloc(1, sizeof(t_map));
	if ((*def)->map == NULL)
	{
		free((*def));
		exit(messages(0));
	}
	create_matrix(def, argv);
	set_size(def);
	(*def)->map->collected = 0;
	(*def)->map->player = 0;
	(*def)->map->collectable = 0;
	(*def)->map->exitpoint = 0;
	(*def)->count_moves = 0;
}

void	create_matrix(t_def **def, const char *argv)
{
	int		i;
	int		fd;
	char	buff[BUFFER_SIZE];

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_free_validation(def, 4, 1);
	i = read(fd, buff, BUFFER_SIZE);
	if (i == 0)
		ft_free_validation(def, 3, 1);
	buff[i] = '\0';
	(*def)->map->buffer = ft_split(buff, '\n');
	if ((*def)->map->buffer == NULL)
		ft_free_validation(def, 0, 1);
	(*def)->map->copy = ft_split(buff, '\n');
	if ((*def)->map->copy == NULL)
		ft_free_validation(def, 0, 2);
	close(fd);
}

void	set_size(t_def **def)
{
	int	i;

	i = 0;
	while ((*def)->map->buffer[0][i])
		i++;
	(*def)->map->w = i;
	(*def)->map->h = 0;
	i = -1;
	while ((*def)->map->buffer[++i])
		(*def)->map->h++;
}

void	ft_free_validation(t_def **def, int i, int flag)
{
	if (flag == 1)
	{
		free((*def)->map);
		free((*def));
		exit(messages(i));
	}
	if (flag == 2)
	{
		flag = -1;
		while (++flag < (*def)->map->h)
			free((*def)->map->buffer[flag]);
		free((*def)->map->buffer);
		free((*def)->map);
		free((*def));
		exit(messages(i));
	}
}
