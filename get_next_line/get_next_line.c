/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:04:04 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/08 13:45:35 by hanbkim          ###   ########.fr       */
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

	buf[0] = '\0';
	while (!has_newline(buf))
	{	
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == 0)
			return (backup);
		if (rd < 0)
			return (NULL);
		buf[rd] = '\0';
		temp = backup;
		if (!backup)
			backup = ft_strdup(buf);
		else
			backup = ft_strjoin(backup, buf);
		if (!backup)
			return (NULL);
	}
	return (backup);
}

static char	*new_next_line(char **backup, t_list **head, int fd)
{
	char	*str;
	char	*temp;
	int		newline_prev;
	int		backup_len;

	temp = *backup;
	backup_len = ft_strlen(temp);
	newline_prev = has_newline(temp);
	str = malloc(newline_prev + 1);
	if (!str)
		return (ft_list_remove_if(head, fd));
	str = ft_memmove(str, temp, newline_prev);
	str[newline_prev] = '\0';
	temp = ft_memmove(temp, temp + newline_prev,
			backup_len - newline_prev);
	temp[backup_len - newline_prev] = '\0';
	return (str);
}

static t_list	*find(t_list **head, int fd)
{
	t_list	*node;
	t_list	*add;

	node = *head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		if (!node->next)
			break ;
		node = node->next;
	}
	add = malloc(sizeof(t_list));
	if (!add)
		return (NULL);
	add->fd = fd;
	add->backup = NULL;
	add->next = NULL;
	if (!node)
		*head = add;
	else
		node->next = add;
	return (add);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*ret;
	size_t			backup_len;

	ret = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (ft_list_remove_if(&head, fd));
	node = find(&head, fd);
	if (!node)
		return (NULL);
	node->backup = read_target(fd, node->backup);
	if (!node->backup)
		return (ft_list_remove_if(&head, fd));
	backup_len = ft_strlen(node->backup);
	if (has_newline(node->backup))
		return (new_next_line(&(node->backup), &head, fd));
	if (*node->backup)
	{
		ret = malloc(backup_len + 1);
		ret = ft_memmove(ret, node->backup, backup_len + 1);
	}
	ft_list_remove_if(&head, fd);
	return (ret);
}
