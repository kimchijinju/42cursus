/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:20 by hanbkim           #+#    #+#             */
/*   Updated: 2022/10/06 15:27:06 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/signal.h>
#include "libft.h"

t_reciver	g_reciver;

int	error(void)
{
	ft_printf("error!\n");
	exit(1);
	return (1);
}

void	true_bit(int signum, siginfo_t *info, void *context)
{	
	(void) context;
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
	usleep(30);
	if (kill(info->si_pid, signum))
		error();
}

void	false_bit(int signum, siginfo_t *info, void *context)
{
	(void) context;
	g_reciver.bit_count++;
	g_reciver.byte <<= 1;
	if (g_reciver.bit_count == 8)
	{
		g_reciver.byte >>= 1;
		write(1, &g_reciver.byte, 1);
		g_reciver.bit_count = 0;
		g_reciver.byte = 0;
	}
	usleep(30);
	if (kill(info->si_pid, signum))
		error();
}

void	set_sigact(struct sigaction *true_sig, struct sigaction *false_sig)
{
	sigemptyset(&(true_sig->sa_mask));
	sigemptyset(&(false_sig->sa_mask));
	true_sig->sa_flags = SA_SIGINFO;
	false_sig->sa_flags = SA_SIGINFO;
	true_sig->sa_sigaction = true_bit;
	false_sig->sa_sigaction = false_bit;
	sigaction(SIGUSR1, true_sig, 0);
	sigaction(SIGUSR2, false_sig, 0);
}

int	main(void)
{
	struct sigaction	true_sig;
	struct sigaction	false_sig;
	const pid_t			pid = getpid();

	ft_printf("server PID : %d\n", pid);
	set_sigact(&true_sig, &false_sig);
	g_reciver.byte = 0;
	g_reciver.bit_count = 0;
	while (1)
	{
		pause();
	}
}
