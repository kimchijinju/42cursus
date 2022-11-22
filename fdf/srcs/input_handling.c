/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:29:05 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 17:14:26 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	translate(int k, t_control *ctrl)
{
	const int	translate_point = 10;

	if (k == K_W)
		ctrl->translate_y -= translate_point;
	if (k == K_S)
		ctrl->translate_y += translate_point;
	if (k == K_A)
		ctrl->translate_x -= translate_point;
	if (k == K_D)
		ctrl->translate_x += translate_point;
}

void	rotate(int k, t_control *ctrl)
{
	const double	rotate_angle = M_PI / 180 * 6;

	if (k == K_K)
		ctrl->rotate_y -= rotate_angle;
	if (k == K_J)
		ctrl->rotate_y += rotate_angle;
	if (k == K_H)
		ctrl->rotate_x -= rotate_angle;
	if (k == K_L)
		ctrl->rotate_x += rotate_angle;
	if (k == K_N)
		ctrl->rotate_z -= rotate_angle;
	if (k == K_M)
		ctrl->rotate_z += rotate_angle;
}

void	increase_height(int k, t_control *ctrl)
{
	const int	increase_value = 10;

	if (k == K_DOT)
		ctrl->increase_z += increase_value;
	if (k == K_COMMA)
		ctrl->increase_z -= increase_value;
}

void	zoom(int k, t_control *ctrl)
{
	const int	increase_value = 10;

	if (k == K_PLUS)
	{
		ctrl->increase_x += increase_value;
		ctrl->increase_y += increase_value;
	}
	if (k == K_MINUS)
	{
		ctrl->increase_x -= increase_value;
		ctrl->increase_y -= increase_value;
	}
}

void	change_projection(int k, t_control *ctrl)
{
	const double	parallel = 0;
	const double	isometric = M_PI / 6;

	if (k == K_P)
		ctrl->projection_type = parallel;
	if (k == K_I)
		ctrl->projection_type = isometric;
	ctrl->rotate_x = 0;
	ctrl->rotate_y = 0;
	ctrl->rotate_z = 0;
}
