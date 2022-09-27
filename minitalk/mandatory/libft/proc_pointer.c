/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:07:04 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/02 11:53:22 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	addr_length(unsigned long long addr)
{
	int	n;

	n = 0;
	while (addr)
	{
		addr /= 16;
		n++;
	}
	return (n);
}

int	print_address(unsigned long long addr)
{
	char	hexa[17];
	int		i;
	int		w_len;

	if (!addr)
		return (write(STDOUT_FILENO, "0x0", 3));
	w_len = addr_length(addr);
	i = w_len - 1;
	hexa[w_len] = '\0';
	while (i >= 0)
	{
		hexa[i--] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	if (write(STDOUT_FILENO, "0x", 2) == -1)
		return (-1);
	return (write(STDOUT_FILENO, hexa, w_len) + 2);
}
