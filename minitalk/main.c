#include <signal.h>
#include <sys/signal.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int byte = 0;
void	recursive(unsigned char n, int server_pid)
{
	if (n == 0)
		return ;
	recursive(n / 2, server_pid);
	if (n % 2 == 1)
		printf("1");
	if (n % 2 == 0)
		printf("0");
}
int main()
{
	int	i;
	i = 0;
	char	*n = "가";
	char byte = 0b11101010;
	char byte1 = 0b10110000;
	char byte2 = 0b10000000;
	write(1, &byte, 1);
	write(1, &byte1, 1);
	write(1, &byte2, 1);
	printf("\n");
	recursive(-22,0);
//	while(n[i])
//	{
//		recursive(n[i], 0);
//		printf("\n");
//		printf("%d", n[i]);
//		i++;
//		printf("\n");
//	}
}
