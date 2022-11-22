/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:04:39 by hanbkim           #+#    #+#             */
/*   Updated: 2022/10/20 17:53:21 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_vergnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_vergnl(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen_vergnl(s1);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_vergnl(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*str;

	s1_len = ft_strlen_vergnl(s1);
	s2_len = ft_strlen_vergnl(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free(s1 - s1_len);
	return (str);
}

void	*ft_memmove_vergnl(void *dst, const void *src, size_t len)
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

char	*ft_list_remove_if_vergnl(t_list **begin_list, int fd)
{
	t_list	*tmp;
	t_list	*i;

	if (*begin_list && (*begin_list)->fd == fd)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp->backup);
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (i->next->fd == fd)
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp->backup);
			free(tmp);
		}
		i = i->next;
	}
	return (NULL);
}
