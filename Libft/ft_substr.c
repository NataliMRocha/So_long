/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:43:54 by namoreir          #+#    #+#             */
/*   Updated: 2023/07/28 16:05:08 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	size_t	source_len;
	char	*substr;

	if (!s)
		return (NULL);
	source_len = ft_strlen(s);
	substr_len = source_len - (size_t)start;
	if (start > source_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > source_len)
		len = source_len - start + 1;
	if (substr_len > len)
		substr_len = len;
	substr = (char *)ft_calloc(substr_len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), len + 1);
	return (substr);
}
