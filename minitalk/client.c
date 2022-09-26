#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define sec 30


static int turn = 0;

void	send_binary_bit(unsigned char n, int server_pid)
{
	if (n == 0)
		return ;
	send_binary_bit(n / 2, server_pid);
	usleep(sec);
	if (n % 2 == 1)
		kill(server_pid, SIGUSR1);
	if (n % 2 == 0)
		kill(server_pid, SIGUSR2);
	pause();
}

void	send_padding_bit(unsigned char n, int server_pid)
{
	int	count;

	count = 0;
	while (n > 0)
	{	
		n /= 2;
		count++;
	}
	for(int i = 0; i < 8 - count; i++)
	{
		usleep(sec);
		kill(server_pid, SIGUSR2);
		pause();
	}
}

void	handler(int signum)
{
	write(1, "catch!\n", 7);
}

int main(int argc, char **argv)
{
	pid_t	server_pid = 0;
	char	*send_string;

	if (argc != 3)
		return (1);

	server_pid = atoi(argv[1]);
	send_string = argv[2];
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(*send_string)
	{
		send_padding_bit(*send_string, server_pid);
		send_binary_bit(*send_string, server_pid);
		send_string++;
	}
}
