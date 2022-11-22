/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:15:58 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 16:54:58 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_tools	mlx_tool;
	t_map	*map;

	if (argc != 2)
	{
		write(2, "invalid argment\n", 16);
		return (1);
	}
	map = parse(argv[1]);
	init_mlx(&mlx_tool);
	mlx_tool.map = map;
	calculate_and_draw(&mlx_tool);
	mlx_key_hook(mlx_tool.mlx_window, key_hook, &mlx_tool);
	mlx_loop(mlx_tool.mlx);
}
