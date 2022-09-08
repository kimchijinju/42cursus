/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:43:12 by hanbkim           #+#    #+#             */
/*   Updated: 2022/07/23 03:03:14 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	cpy(char *dest, char const *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (s_len - start < len)
		len = s_len - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	cpy(str, s + start, len);
	return (str);
}
