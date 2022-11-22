/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:54:10 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 17:15:18 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_tools *mlx_tool, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = mlx_tool->addr
		+ (y * mlx_tool->line_length + x * (mlx_tool->bits_per_pixel / 8));
	*((unsigned int *)dst) = color;
}

int	key_hook(int k, t_tools *mlx_tool)
{
	if (k == K_ESC)
	{
		mlx_destroy_window(mlx_tool->mlx, mlx_tool->mlx_window);
		exit(0);
	}
	if (k == K_I || k == K_P)
		change_projection(k, mlx_tool->ctrl);
	if (k == K_H || k == K_L || k == K_J || k == K_K || k == K_N || k == K_M)
		rotate(k, mlx_tool->ctrl);
	if (k == K_W || k == K_S || k == K_A || k == K_D)
		translate(k, mlx_tool->ctrl);
	if (k == K_COMMA || k == K_DOT)
		increase_height(k, mlx_tool->ctrl);
	if (k == K_MINUS || k == K_PLUS)
		zoom(k, mlx_tool->ctrl);
	calculate_and_draw(mlx_tool);
	return (0);
}

void	set_mlx_img(t_tools *mlx_tool)
{
	if (mlx_tool->img)
		mlx_destroy_image(mlx_tool->mlx, mlx_tool->img);
	mlx_tool->img = mlx_new_image(mlx_tool->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx_tool->img)
		error_handling("mlx_new_image");
	mlx_tool->addr = mlx_get_data_addr(mlx_tool->img, &mlx_tool->bits_per_pixel,
			&mlx_tool->line_length, &mlx_tool->endian);
}

void	init_ctrl(t_tools *mlx_tool)
{
	mlx_tool->ctrl = malloc(sizeof(t_control));
	if (!mlx_tool->ctrl)
		error_handling("malloc");
	mlx_tool->ctrl->increase_x = 0;
	mlx_tool->ctrl->increase_y = 0;
	mlx_tool->ctrl->increase_z = 0;
	mlx_tool->ctrl->rotate_x = 0;
	mlx_tool->ctrl->rotate_y = 0;
	mlx_tool->ctrl->rotate_z = 0;
	mlx_tool->ctrl->translate_x = 0;
	mlx_tool->ctrl->translate_y = 0;
	mlx_tool->ctrl->projection_type = M_PI / 6;
}

void	init_mlx(t_tools *mlx_tool)
{
	mlx_tool->mlx = mlx_init();
	if (!mlx_tool)
		error_handling("init_mlx");
	mlx_tool->mlx_window = mlx_new_window(mlx_tool->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "hanbkim");
	if (!mlx_tool->mlx_window)
		error_handling("mlx_new_window");
	mlx_tool->img = NULL;
	init_ctrl(mlx_tool);
}
