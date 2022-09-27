/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:20 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/27 14:02:41 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "libft.h"

t_reciver	g_reciver;

int	error(void)
{
	ft_printf("error!\n");
	exit(1);
	return (1);
}

void	true_bit(int signum)
{	
	(void) signum;
	g_reciver.byte |= 1;
	g_reciver.bit_count++;
	g_reciver.byte <<= 1;
	if (g_reciver.bit_count == 8)
	{
		g_reciver.byte >>= 1;
		write(1, &g_reciver.byte, 1);
		g_reciver.bit_count = 0;
		g_reciver.byte = 0;
	}
}

void	false_bit(int signum)
{
	(void) signum;
	g_reciver.bit_count++;
	g_reciver.byte <<= 1;
	if (g_reciver.bit_count == 8)
	{
		g_reciver.byte >>= 1;
		write(1, &g_reciver.byte, 1);
		g_reciver.bit_count = 0;
		g_reciver.byte = 0;
	}
}

int	main(void)
{
	const pid_t			pid = getpid();

	ft_printf("server PID : %d\n", pid);
	signal(SIGUSR1, true_bit);
	signal(SIGUSR2, false_bit);
	g_reciver.byte = 0;
	g_reciver.bit_count = 0;
	while (1)
	{
	}
}
