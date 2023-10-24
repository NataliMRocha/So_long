/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:14:44 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/23 20:46:37 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	size;
	int	i;

	size = 0;
	if (str)
	{
		i = 0;
		while (str[i])
		{
			write(1, &str[i], 1);
			size++;
			i++;
		}
	}
	else
		size += write(1, "(null)", 6);
	return (size);
}
