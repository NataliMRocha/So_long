/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:30:22 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/17 20:18:10 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	long int	i;
	int			size;

	i = nb;
	size = 0;
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
		size++;
	}
	if (i >= 10)
		size += ft_putnbr(i / 10);
	size += ft_putchar(i % 10 + '0');
	return (size);
}

int	ft_putnbr_uns(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb >= 10)
		size += ft_putnbr_uns(nb / 10);
	size += ft_putchar(nb % 10 + '0');
	return (size);
}

int	ft_putnbr_hx(unsigned int hx, char *base)
{
	int			size;

	size = 0;
	if (hx < 16)
		size += ft_putchar(base[hx % 16]);
	else if (hx >= 16)
	{
		size += ft_putnbr_hx(hx / 16, base);
		size += ft_putchar(base[hx % 16]);
	}
	return (size);
}

int	ft_putptr(unsigned long ptr, char *base)
{
	int			size;

	if ((void *)ptr == NULL || ptr == 0)
	{
		write(1, "(nil)", 5);
		size = 5;
		return (size);
	}
	size = 0;
	if (ptr < 16)
	{
		write(1, "0x", 2);
		size = 2;
		size += ft_putchar(base[ptr % 16]);
	}
	else if (ptr >= 16)
	{
		size += ft_putptr(ptr / 16, base);
		size += ft_putchar(base[ptr % 16]);
	}
	return (size);
}
