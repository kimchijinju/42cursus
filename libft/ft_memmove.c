/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:42:52 by hanbkim           #+#    #+#             */
/*   Updated: 2022/07/23 03:04:05 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (src > dst)
	{
		while (len)
		{
			len--;
			*d++ = *s++;
		}
	}
	else if (src < dst)
	{
		while (len)
		{
			len--;
			d[len] = s[len];
		}
	}
	return (dst);
}
