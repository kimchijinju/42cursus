/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:53:17 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/21 13:56:44 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(double x, int *y, int *z)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x) + (*z) * sin(x);
	*z = -prev_y * sin(x) + (*z) * cos(x);
}

void	rotate_y(int *x, double y, int *z)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y) + (*z) * sin(y);
	*z = -prev_x * sin(y) + (*z) * cos(y);
}

void	rotate_z(int *x, int *y, double z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(z) - prev_y * sin(z);
	*y = prev_x * sin(z) + prev_y * cos(z);
}
