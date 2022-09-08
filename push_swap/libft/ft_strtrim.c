/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:43:11 by hanbkim           #+#    #+#             */
/*   Updated: 2022/07/23 15:31:28 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len > 0 && ft_strchr(set, s1[s1_len]))
		s1_len--;
	return (ft_substr(s1, 0, s1_len + 1));
}
