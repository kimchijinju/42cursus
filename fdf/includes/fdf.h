/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:11:06 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 17:13:38 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

enum e_input
{
	K_ESC = 53,
	K_W = 13,
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_H = 4,
	K_L = 37,
	K_J = 38,
	K_K = 40,
	K_N = 45,
	K_M = 46,
	K_I = 34,
	K_P = 35,
	K_COMMA = 43,
	K_DOT = 47,
	K_MINUS = 27,
	K_PLUS = 24
};

typedef struct s_tools		t_tools;
typedef struct s_point		t_point;
typedef struct s_map		t_map;
typedef struct s_control	t_control;

typedef struct s_tools
{
	void		*mlx;
	void		*mlx_window;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_control	*ctrl;
}	t_tools;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	t_point	*point;
	int		max;
	int		width;
	int		height;
	int		distance;
	int		ratio;
}	t_map;

typedef struct s_control
{
	int		translate_x;
	int		translate_y;
	double	rotate_x;
	double	rotate_y;
	double	rotate_z;
	double	projection_type;
	int		increase_x;
	int		increase_y;
	int		increase_z;
}	t_control;

t_map		*parse(char *file);
void		calculate_and_draw(t_tools *mlx_tool);
void		my_mlx_pixel_put(t_tools *mlx_tool, int x, int y, int color);
void		set_mlx_img(t_tools *mlx_tool);
void		translate(int k, t_control *ctrl);
void		rotate(int k, t_control *ctrl);
void		change_projection(int k, t_control *ctrl);
void		increase_height(int k, t_control *ctrl);
void		zoom(int k, t_control *ctrl);
void		rotate_x(double x, int *y, int *z);
void		rotate_y(int *x, double y, int *z);
void		rotate_z(int *x, int *y, double z);
const char	**read_map(char *file, const int row_size);
int			get_col_count(const char *col);
int			get_row_count(char *file);
void		init_mlx(t_tools *mlx_tool);
void		init_ctrl(t_tools *mlx_tool);
void		set_mlx_img(t_tools *mlx_tool);
int			key_hook(int k, t_tools *mlx_tool);
void		my_mlx_pixel_put(t_tools *mlx_tool, int x, int y, int color);

#endif
