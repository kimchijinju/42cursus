#include <stdio.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

struct sigaction true_sig;
struct sigaction false_sig;

int	count = 0;
int	byte = 0;

#define sec 250

void	true_bit(int signum, siginfo_t *info, void *context)
{	
	byte |= 1;
	if (count != 7)
		byte = byte << 1;
	count += 1;
	if (count == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		count = 0;
	}
	usleep(sec);
	kill(info->si_pid, signum);
}

void	false_bit(int signum, siginfo_t *info, void *context)
{	
	if (count != 7)
		byte = byte << 1;
	count += 1;
	if (count == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		count = 0;
	}
	usleep(sec);
	kill(info->si_pid, signum);
}

int main()
{
	pid_t pid = getpid();

	true_sig.sa_flags = SA_SIGINFO;
	true_sig.sa_sigaction = true_bit;
	false_sig.sa_flags = SA_SIGINFO;
	false_sig.sa_sigaction = false_bit;

	printf("server PID : %d\n", pid);

	sigaction(SIGUSR1, &true_sig, 0);
	sigaction(SIGUSR2, &false_sig, 0);
	while(1)
	{
		pause();
	}
}
