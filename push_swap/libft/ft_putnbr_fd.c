/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:42:58 by hanbkim           #+#    #+#             */
/*   Updated: 2022/07/21 14:59:28 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(long long nb, int fd)
{
	char	n;

	if (nb < 0)
	{
		write(fd, "-", 1);
		putnbr(-nb, fd);
		return ;
	}
	if (nb >= 10)
		putnbr(nb / 10, fd);
	n = nb % 10 + '0';
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	putnbr(n, fd);
}
