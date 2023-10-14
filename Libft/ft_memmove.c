/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:36:06 by namoreir          #+#    #+#             */
/*   Updated: 2023/07/20 15:27:47 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (p_dest == p_src)
		return (dest);
	if (p_dest < p_src)
	{
		while (n--)
			*p_dest++ = *p_src++;
	}
	else
	{
		p_dest += n;
		p_src += n;
		while (n--)
			*--p_dest = *--p_src;
	}
	return (dest);
}
