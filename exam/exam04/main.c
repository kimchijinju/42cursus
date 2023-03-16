#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

pid_t pid[200];

void microshell(char **argv, char **envp)
{
	int fds[2];
	int prev_pipe_in = -1;
	int	pid_count = 0;

	int i = 0;
	while (argv[i])
	{
		bool is_pipe = false;
		int j = i;
		while (argv[j] && strcmp(argv[j], "|") != 0)
			++j;
		if (argv[j] && strcmp(argv[j], "|") == 0)
			is_pipe = true;

		if (is_pipe)
			pipe(fds);

		pid[pid_count++] = fork();

		if (pid[pid_count - 1] == 0)
		{
			if (prev_pipe_in != -1)
			{
				dup2(prev_pipe_in, 0);
				close(prev_pipe_in);
			}
			if (is_pipe)
			{
				dup2(fds[1], 1);
				close(fds[1]);
				close(fds[0]);
			}
			argv[j] = NULL;
			execve(argv[i], argv + i, envp);
		}
		if (prev_pipe_in != -1)
			close(prev_pipe_in);
		if (is_pipe)
		{
			prev_pipe_in = fds[0];
			close(fds[1]);
			++j;
		}
		i = j;
	}
	for (int i = 0; i < pid_count; ++i)
		waitpid(pid[i], NULL, 0);

}

int main(int argc, char **argv, char **envp)
{
	int i = 1;
	while (i < argc)
	{
		int j = i;
		while (argv[j] && strcmp(argv[j], ";") != 0)
			++j;
		argv[j] = NULL;
		microshell(argv + i, envp);
		i = ++j;

	}

}
