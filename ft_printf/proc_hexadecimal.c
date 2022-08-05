/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hexadecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:13:33 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/02 10:23:51 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int nb)
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
		nb /= 16;
		size++;
	}
	return (size);
}

static int	put(unsigned int nb, char *str, char *format)
{
	int	i;
	int	ret;

	ret = get_size(nb);
	i = ret;
	if (nb == 0)
		str[0] = '0';
	str[i--] = '\0';
	while (nb)
	{
		str[i--] = format[nb % 16];
		nb /= 16;
	}
	return (ret);
}

int	print_hexadecimal(unsigned int n, int flag)
{
	char	str[12];
	int		w_len;
	char	*format;

	if (flag)
		format = "0123456789ABCDEF";
	else
		format = "0123456789abcdef";
	w_len = put(n, str, format);
	return (write(STDOUT_FILENO, str, w_len));
}
