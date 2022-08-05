/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:04:04 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/05 13:39:18 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	has_newline(char *buf)
{
	int	i;

	i = 0;
	while(buf[i])
	{
		if(buf[i] == '\n')
			return (i + 1);	
		i++;	
	}
	return (0);
}

char	*read_target(int fd, char *backup)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int rd;
	
	buf[0] = '\0';
	while (!has_newline(buf))
	{	
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == 0)
			return (backup);
		if (rd < 0)
		{
			free(backup);
			return (0);
		}
		buf[rd] = '\0';
		temp = backup;
		if (!backup)
			backup = ft_strdup(buf);
		else
			backup = ft_strjoin(backup, buf);
	}
	free(temp);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char *backup;
	char *str;
	int	newline_prev;
	int	backup_len;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = read_target(fd, backup);
	if (!backup)
		return (0);
	backup_len = ft_strlen(backup);
	newline_prev = has_newline(backup);
	if(newline_prev)
	{
		str = malloc(newline_prev + 1);
		if (!str)
		{
			free(backup);
			return (0);
		}
		str = ft_memmove(str, backup, newline_prev);
		str[newline_prev] = '\0';
		backup = ft_memmove(backup, backup + newline_prev, ft_strlen(backup) - newline_prev);
		backup[ft_strlen(backup) - newline_prev] = '\0';
		return str;
	}
	if(*backup)
	{
		str = malloc(backup_len + 1);
		str = ft_memmove(str, backup, backup_len + 1);
	}
	else
		str = 0;
	free(backup);
	backup = 0;	
	return (str);
}

int main()
{
	int fd = open("1char.txt", O_RDONLY);
	char *str;
	str = 0;
	while (1)
	{
		str = get_next_line(1);
		if(!str)
			return (1);
		printf("ret : %s", str);
		free(str);
	}
}
