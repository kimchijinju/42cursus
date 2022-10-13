#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "./libft/libft.h"

void	pipex(int argc, char **argv, t_list *cmd_bundle)
{
	pid_t   child_pid;

	int fds[2];

	int	fdin;
	int fdout;

	fdin = open(argv[1], O_RDONLY);

	int i = 2;
	while (i < argc - 1)
	{
		dup2(fdin, 0);
		close(fdin);
		if (i == argc - 2)
		{
			fdout = open("outfile", O_CREAT | O_WRONLY, 00666);
		}
		else
		{
			pipe(fds);
			fdin = fds[0];
			fdout = fds[1];
		}
		dup2(fdout, 1);
		close(fdout);
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(cmd_bundle->cmd, cmd_bundle->cmd_list, 0);
		}
		cmd_bundle = cmd_bundle->next;
		i++;
	}
	waitpid(child_pid, NULL, 0);
}

t_list	*init_cmd_list(int argc, char **argv)
{
	t_list	*head;
	t_list	*add;
	int	i;

	i = 2;
	head = NULL;
	while (i < argc - 1)
	{
		add = ft_lstnew(argv[i]);
		ft_lstadd_back(&head, add);
		i++;
	}

	return (head);
}

char	*put_accessible_path_cmd(char **path, char *cmd_name)
{
	int	i;
	char	*path_and_cmd;

	i = 0;
	while (path[i])
	{
		path_and_cmd = ft_strjoin(path[i], cmd_name); 
		if (access(path_and_cmd, F_OK | X_OK) == 0)
		{
			return (path_and_cmd);
		}
		free(path_and_cmd);
		i++;
	}
	return (cmd_name);
}

t_list	*init_cmd(int argc, char **path, t_list *node)
{
	int	i;
	
	const t_list	*ret = node;

	i = 2;
	while (i < argc - 1)
	{
		node->cmd = put_accessible_path_cmd(path, node->cmd_list[0]);
		node = node->next;
		i++;
	}
	return (t_list *)(ret);
}

int	get_path_index(char	**envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**cut_name_and_put_dir(char *path_var)
{
	char	**path_list;
	char	*temp;
	int		i;
	
	path_var = ft_substr(path_var, 5, ft_strlen(path_var) - 5);
	path_list = ft_split(path_var, ':');
	i = 0;
	while (path_list[i])
	{
		temp = path_list[i];
		path_list[i] = ft_strjoin(path_list[i], "/");
		free(temp);
		i++;
	}
	free(path_var);
	return (path_list);
}

int main(int argc, char **argv, char **envp)
{
	t_list	*head;
	char	**path;
	int		path_index;

	if (argc < 5)
		return (1);
	path_index = get_path_index(envp);
	path = cut_name_and_put_dir(envp[path_index]);
	head = init_cmd_list(argc, argv);
	init_cmd(argc, path, head);
	pipex(argc, argv, head);
}
