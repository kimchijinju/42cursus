/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:42:40 by hanbkim           #+#    #+#             */
/*   Updated: 2022/07/21 14:51:52 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long long nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
	{
		size++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static void	put(long long nb, char *str)
{
	int	i;

	i = get_size(nb);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[i--] = '\0';
	while (nb)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc(sizeof(char) * get_size(n) + 1);
	if (!str)
		return (NULL);
	put(n, str);
	return (str);
}
