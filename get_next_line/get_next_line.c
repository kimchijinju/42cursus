/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:04:04 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/07 18:06:22 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	has_newline(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static char	*read_target(int fd, char *backup)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	rd;

	while (!has_newline(buf))
	{	
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == 0)
			return (backup);
		if (rd < 0)
		{
			free(backup);
			return (NULL);
		}
		buf[rd] = '\0';
		temp = backup;
		if (!backup)
			backup = ft_strdup(buf);
		else
		{
			backup = ft_strjoin(backup, buf);
			free(temp);
		}
	}
	return (backup);
}

static char	*new_next_line(char **backup, int newline_prev, int backup_len)
{
	char	*str;
	char	*temp;

	temp = *backup;
	str = malloc(newline_prev + 1);
	if (!str)
	{
		free(backup);
		return (0);
	}
	str = ft_memmove(str, temp, newline_prev);
	str[newline_prev] = '\0';
	temp = ft_memmove(temp, temp + newline_prev,
			backup_len - newline_prev);
	temp[backup_len - newline_prev] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*str;
	size_t		newline_prev;
	size_t		backup_len;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_target(fd, backup);
	if (!backup)
		return (NULL);
	backup_len = ft_strlen(backup);
	newline_prev = has_newline(backup);
	if (newline_prev)
		return (new_next_line(&backup, newline_prev, backup_len));
	if (*backup)
	{
		str = malloc(backup_len + 1);
		str = ft_memmove(str, backup, backup_len + 1);
	}
	free(backup);
	backup = 0;
	return (str);
}
