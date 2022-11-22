/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:52 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 17:12:48 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	set_point(const char *char_map, t_map *map)
{
	char	**col;
	char	**height_color;
	int		i;

	col = ft_split(char_map, ' ');
	i = 0;
	while (col[i])
	{
		if (col[i][0] == '\n')
			break ;
		height_color = ft_split(col[i], ',');
		map->point[map->max].z = ft_atoi(height_color[0]);
		if (height_color[1] == NULL)
			map->point[map->max].color = 0xFFFFFF;
		else
			map->point[map->max].color = ft_atoi_hexa(height_color[1]);
		map->max++;
		i++;
		free_split(height_color);
	}
	free_split(col);
}

void	set_distance_ratio(t_map *map)
{
	int	ratio;
	int	distance;

	if (WINDOW_WIDTH / map->width < WINDOW_HEIGHT / map->height)
		distance = WINDOW_WIDTH / map->width;
	else
		distance = WINDOW_HEIGHT / map->height;
	if (distance > 100)
		ratio = 4;
	else if (distance > 50)
		ratio = 3;
	else
		ratio = 2;
	map->ratio = ratio;
	map->distance = distance / ratio;
}

t_map	*convert(const char **char_map, int row, int col)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	map->point = malloc(sizeof(t_point) * row * col);
	map->max = 0;
	map->height = row;
	map->width = col;
	set_distance_ratio(map);
	i = 0;
	while (char_map[i])
	{
		set_point(char_map[i], map);
		i++;
	}
	return (map);
}

t_map	*parse(char *file)
{
	const int	row = get_row_count(file);
	const char	**char_map = read_map(file, row);
	const int	col = get_col_count(char_map[0]);
	t_map		*map;

	map = convert(char_map, row, col);
	free_split((char **)char_map);
	return (map);
}
