/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:31:49 by natali            #+#    #+#             */
/*   Updated: 2023/10/23 20:58:35 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	messages(int i)
{
	const char	*message[13] = {
		"Dynamic memory allocation has failed =/",
		"Please provide one and only one argument.\n"
		"It should be something like: \"./so_long map.ber\"",
		"This file isn't valid.\nMake sure it's a file with '.ber' extension.",
		"This file is empty, help me to help you!",
		"Error while opening file. Please check the path of file.",
		"Your map don't have all the necessary sttuf.\n"
		"You need 1 Player(P), 1 Exit point(E), at least 1 collectable(C),\n"
		"be surrounded by walls(1).\nYou can use the maps suggested in ./maps!",
		"You need at least one and only one player(P).\n"
		"Joquinha doesn't accept clones!",
		"You need at least one exit point. You don't want to get stuck, right?",
		"You don't wanna have fun?? You need to be collectables!",
		"Your map needs to be rectangular.",
		"Problem during mlx initialize",
		"You have arrived at the oasis! Congratulations!!!",
		"You didn't like my game =/"
	};

	if (i <= 10)
		ft_printf("Error\n%s\n", message[i]);
	else
		ft_printf("%s\n", message[i]);
	return (i);
}