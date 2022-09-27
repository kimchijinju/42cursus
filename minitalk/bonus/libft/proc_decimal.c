/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:04:00 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/02 11:17:09 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	put(long long nb, char *str)
{
	int	i;
	int	ret;

	ret = get_size(nb);
	i = ret;
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
	return (ret);
}

int	print_decimal(int n)
{
	char	str[12];
	int		w_len;

	w_len = put(n, str);
	return (write(STDOUT_FILENO, str, w_len));
}

int	print_unsigned_decimal(unsigned int n)
{
	char	str[11];
	int		w_len;

	w_len = put(n, str);
	return (write(STDOUT_FILENO, str, w_len));
}
