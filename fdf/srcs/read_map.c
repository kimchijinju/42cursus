/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:52 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 17:12:57 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

int	get_row_count(char *file)
{
	const int	fd = open(file, O_RDONLY);
	int			count;
	char		*line;

	if (fd < 0)
		error_handling("open");
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		count++;
	}
	if (close(fd) < 0)
		error_handling("close");
	return (count);
}

int	get_col_count(const char *map)
{
	int		i;
	int		count;
	char	**col;

	col = ft_split(map, ' ');
	i = 0;
	count = 0;
	while (col[i])
	{
		if (col[i][0] != '\n')
			count++;
		i++;
	}
	free_split(col);
	return (count);
}

const char	**read_map(char *file, const int row)
{
	const int	fd = open(file, O_RDONLY);
	const char	**map;
	int			i;

	if (fd < 0)
		error_handling("open");
	map = malloc(sizeof(char *) * (row + 1));
	if (!map)
		error_handling("malloc");
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
		{
			if (close(fd) < 0)
				error_handling("close");
			return (map);
		}
		i++;
	}
	return (NULL);
}
