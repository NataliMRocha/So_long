/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:59:42 by natali            #+#    #+#             */
/*   Updated: 2023/10/20 18:08:26 by namoreir         ###   ########.fr       */
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
		close_game(def, 2);
		exit(messages(5));
	}
	i = validate_map2(def);
	if (i != 0)
	{
		close_game(def, 2);
		exit(messages(i));
	}
}

void	input_validation(int argc, const char *argv, t_def **def)
{
	int	i;

	if(argc != 2)
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
	(*def)->map->w = 0;
	read_line(def, argv);
	create_matrix(def, argv, 'b');
	create_matrix(def, argv, 'v');
}

void	read_line(t_def **def, const char *argv)
{
	int		fd;
	int		size;
	int		i;
	char	buffer[BUFFER_SIZE];

	fd = open(argv, O_RDONLY);
	if(fd == -1)
		ft_free_validation(def, 4);
	size = read(fd, buffer, BUFFER_SIZE);
	if(size == 0)
		ft_free_validation(def, 3);
	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			break ;
		(*def)->map->w++;
	}
	if ((*def)->map->w)
		(*def)->map->h = size / (*def)->map->w;
	close(fd);
}

void	create_matrix(t_def **def, const char *argv, char flag)
{
	int		i;
	int		j;
	int		fd;
	char	buff[BUFFER_SIZE];
	
	fd = open(argv, O_RDONLY);
	j = read(fd, buff, BUFFER_SIZE);
	buff[j] = '\0';
	if (flag == 'v')
	{	
		(*def)->map->validate = ft_split(buff, '\n');
		if ((*def)->map->validate == NULL)
			ft_free_validation(def, 0);
	}
	else
	{
		(*def)->map->buffer = ft_split(buff, '\n');
		if ((*def)->map->buffer == NULL)
			ft_free_validation(def, 0);
	}
	close(fd);
	(*def)->map->player = 0;
	(*def)->map->collectable = 0;
	(*def)->map->exitpoint = 0;
	(*def)->count_moves = 0;
}

void	ft_free_validation(t_def **def, int i)
{
	free((*def)->map);
	free((*def));
	exit(messages(i));
}
