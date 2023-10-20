/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:31:49 by natali            #+#    #+#             */
/*   Updated: 2023/10/20 17:03:43 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	messages(int i)
{
	const char	*message[9] = {
		// 0
		"Dynamic memory allocation has failed =/",
		// mais de 1 argumento 1
		"Please provide one and only one argument.\n"
		"It should be something like: \"./so_long map.ber\"",
		// não termina com .ber 2
		"This file isn't valid.\nMake sure it's a file with '.ber' extension.",
		// arquivo vazio 3
		"This file is empty, help me to help you!",
		// não foi possível ler o arquivo, verificar o caminho 4
		"Error while opening file. Please check the path of file.",
		// mapa sem todos os itens necessários 5
		"Your map don't have all the necessary sttuf.\n"
		"You need 1 Player(P), 1 Exit point(E), at least 1 collectable(C),\n"
		"be surrounded by walls(1) and have ground to walk on(0).\n"
		"Oh! And the map needs to be rectangular.\n"
		"You can use the maps suggested in ./maps!",
		// tem mais de 1 player 6
		"You need at least one and only one player(P).\n"
		"Joquinha doesn't accept clones!"
		//Mais de 1 ponto de saída 7
		"You need at least one exit point. You don't want to get stuck, right?."
		//sem coletáveis 8
		"You don't wanna have fun?? You need to be collectables!",
		//não é retangular 9
		"Your map needs to be rectangular.\n"
		};
	ft_printf("Error\n%s\n", message[i]);
	return (i);
}
