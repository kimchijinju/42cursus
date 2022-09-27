/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:11 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/27 14:04:57 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "libft.h"

int	error(void)
{
	ft_printf("error!\n");
	exit(1);
	return (1);
}

void	send_binary_bit(unsigned char n, int server_pid)
{
	if (n == 0)
		return ;
	send_binary_bit(n / 2, server_pid);
	if (n % 2 == 1)
	{
		if (kill(server_pid, SIGUSR1))
			error();
	}
	if (n % 2 == 0)
	{
		if (kill(server_pid, SIGUSR2))
			error();
	}
	usleep(50);
}

void	send_padding_bit(unsigned char n, int server_pid)
{
	int	padding;
	int	i;

	padding = 0;
	while (n > 0)
	{	
		n /= 2;
		padding++;
	}
	i = 0;
	while (i < 8 - padding)
	{
		i++;
		if (kill(server_pid, SIGUSR2))
			error();
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*send_string;

	if (argc != 3)
		return (error());
	server_pid = ft_atoi(argv[1]);
	send_string = argv[2];
	while (*send_string)
	{
		send_padding_bit(*send_string, server_pid);
		send_binary_bit(*send_string, server_pid);
		send_string++;
	}
}
