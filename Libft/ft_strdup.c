/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:21:27 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/23 20:46:49 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*strdup;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	strdup = (char *)ft_calloc((len + 1), sizeof(char));
	if (strdup == NULL)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		strdup[i] = s[i];
		i++;
	}
	return (strdup);
}
