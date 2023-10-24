/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:38:31 by namoreir          #+#    #+#             */
/*   Updated: 2023/07/27 14:54:38 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	tofind;

	p = (unsigned char *)s;
	tofind = (unsigned char)c;
	while (n--)
	{
		if (*p == tofind)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
