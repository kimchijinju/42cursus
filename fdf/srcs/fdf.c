/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:53:04 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 17:13:57 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "mlx.h"

void	init_bresenham_info(t_point *d, t_point *s,
		t_point *start, t_point *end)
{
	d->x = ft_abs(end->x - start->x);
	d->y = -ft_abs(end->y - start->y);
	if (start->x < end->x)
		s->x = 1;
	else
		s->x = -1;
	if (start->y < end->y)
		s->y = 1;
	else
		s->y = -1;
}

void	plot_line(t_point *start, t_point *end, t_tools *mlx_tool)
{
	t_point	d;
	t_point	s;
	int		err[2];

	init_bresenham_info(&d, &s, start, end);
	err[0] = d.x + d.y;
	while (1)
	{
		my_mlx_pixel_put(mlx_tool, start->x, start->y, start->color);
		if (start->x == end->x && start->y == end->y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= d.y)
		{
			err[0] += d.y;
			start->x += s.x;
		}
		if (err[1] <= d.x)
		{
			err[0] += d.x;
			start->y += s.y;
		}
	}
	free(start);
	free(end);
}

static void	projection(int *x, int *y, int z, const t_control *ctrl)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(ctrl->projection_type);
	*y = (prev_x + prev_y) * sin(ctrl->projection_type) - z;
}

static t_point	*get_point(const t_map *map,
		const t_control *ctrl, int x, int y)
{
	const int		i = map->width * y + x;
	t_point			*ret;

	ret = malloc(sizeof(t_point));
	if (!ret)
		error_handling("malloc");
	ret->x = x * (map->distance + ctrl->increase_x)
		- (map->width * map->distance);
	ret->y = y * (map->distance + ctrl->increase_y)
		- (map->height * map->distance);
	ret->z = map->point[i].z * (map->ratio + ctrl->increase_z);
	ret->color = map->point[i].color;
	rotate_x(ctrl->rotate_x, &ret->y, &ret->z);
	rotate_y(&ret->x, ctrl->rotate_y, &ret->z);
	rotate_z(&ret->x, &ret->y, ctrl->rotate_z);
	projection(&ret->x, &ret->y, ret->z, ctrl);
	ret->x = (ret->x + WINDOW_WIDTH / 2) + ctrl->translate_x;
	ret->y = (ret->y + WINDOW_HEIGHT / 2)
		+ (map->height * map->distance / map->ratio) + ctrl->translate_y;
	return (ret);
}

void	calculate_and_draw(t_tools *mlx_tool)
{
	const t_map	*map = mlx_tool->map;
	int			x;
	int			y;

	set_mlx_img(mlx_tool);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				plot_line(get_point(map, mlx_tool->ctrl, x, y),
					get_point(map, mlx_tool->ctrl, x + 1, y), mlx_tool);
			if (y < map->height - 1)
				plot_line(get_point(map, mlx_tool->ctrl, x, y),
					get_point(map, mlx_tool->ctrl, x, y + 1), mlx_tool);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_tool->mlx,
		mlx_tool->mlx_window, mlx_tool->img, 0, 0);
}
