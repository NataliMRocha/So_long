/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:31:49 by natali            #+#    #+#             */
/*   Updated: 2023/10/25 14:26:54 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	messages(int i)
{
	const char	*message[14] = {
		"Dynamic memory allocation has failed =/",
		"Please provide one and only one argument.\n",
		"This file isn't valid.\nMake sure it's a file with '.ber' extension.",
		"This file is empty, help me to help you!",
		"Can't opening file. Please check the path of file.",
		"Your map isn't valid.\n"
		"You need 1 Player(P), 1 Exit point(E), at least 1 collectable(C),\n"
		"be surrounded by walls(1).\nYou can use the maps suggested in ./maps!",
		"You need at least one and only one player(P).\n",
		"You need at least one and only one exit point!",
		"You don't wanna have fun?? You need collectables!",
		"Your map needs to be rectangular.",
		"Problem during mlx initialize",
		"You didn't like my game =/",
		"You have arrived at the oasis! Congratulations!!!",
		"You loose =/"
	};

	if (i <= 10)
		ft_printf("Error\n%s\n", message[i]);
	else
		ft_printf("%s\n", message[i]);
	return (i);
}
