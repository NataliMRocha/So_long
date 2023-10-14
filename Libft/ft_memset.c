/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:23:10 by namoreir          #+#    #+#             */
/*   Updated: 2023/07/20 15:36:17 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	c_n;

	p_s = (unsigned char *)s;
	c_n = (unsigned char)c;
	while (n-- > 0)
	{
		*p_s = c_n;
		p_s++;
	}
	return (s);
}
