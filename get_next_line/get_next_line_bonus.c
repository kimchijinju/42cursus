/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:04:04 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/07 18:59:45 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_list	*find(t_list **head, int fd)
{
	t_list	*node;
	t_list	*add;

	node = *head;
	if (!node)
	{
		node->next = NULL;
		node->backup = NULL;
		node->fd = fd;
		return (node);
	}
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	add->fd = fd;
	add->backup = NULL;
	add->next = NULL;
	node->next = node;
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*ret;
	size_t			newline_prev;
	size_t			backup_len;

	node = find(&head, fd);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node->backup = read_target(fd, node->backup);
	if (!node->backup)
		return (NULL);
	backup_len = ft_strlen(node->backup);
	newline_prev = has_newline(node->backup);
	if (newline_prev)
		return (new_next_line(&(node->backup), newline_prev, backup_len));
	if (!*(node->backup))
	{
		ret = malloc(backup_len + 1);
		ret = ft_memmove(ret, node->backup, backup_len + 1);
	}
	free(node->backup);
	node->backup = 0;
	return (ret);
}
