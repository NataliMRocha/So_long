/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:31:49 by natali            #+#    #+#             */
/*   Updated: 2023/10/24 17:30:02 by namoreir         ###   ########.fr       */
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
		"Can't opening file. Please check the path of file.",
		"Your map isn't valid.\n"
		"You need 1 Player(P), 1 Exit point(E), at least 1 collectable(C),\n"
		"be surrounded by walls(1).\nYou can use the maps suggested in ./maps!",
		"You need at least one and only one player(P).\n"
		"Joquinha doesn't accept clones!",
		"You need at least one and only one exit point!",
		"You don't wanna have fun?? You need collectables!",
		"Your map needs to be rectangular.",
		"Problem during mlx initialize",
		"You didn't like my game =/",
		"You have arrived at the oasis! Congratulations!!!"
	};

	if (i <= 10)
		ft_printf("Error\n%s\n", message[i]);
	else
		ft_printf("%s\n", message[i]);
	return (i);
}
