#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

// parent process save input / output and restore it at the end.
int	main(void)
{
	int command_num;

	// number of command from the parser
	command_num = 10;
	// save in/out

	// < infile
	int fdin;
	fdin = open("infile", O_CREAT | O_RDONLY);

	pid_t pid;
	int fdout;
	int i;

	i = 0;
	while (i < command_num)
	{
		dup2(fdin, 0); // redirect input 
		if (i == command_num - 1)
			fdout = open("outfile", O_CREAT | O_WRONLY);
		else
		{
			int fdpipe[2];
			pipe(fdpipe);
			fdout = fdpipe[1];
			fdin = fdpipe[0];
		}
		pid = fork();
		//child
		if (pid == 0)
		{
			//execve(parsing argument);
		}	
		i++;
	}
	waitpid(pid, NULL, 0);
	return (0);
}
