/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:42:56 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/03 11:16:38 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digit(long int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		int_size;
	size_t		index;
	long int	nb;

	nb = n;
	int_size = ft_count_digit(n);
	str = (char *)ft_calloc((int_size + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	index = int_size - 1;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[index--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
