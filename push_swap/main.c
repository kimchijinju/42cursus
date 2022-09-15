/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:39:25 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/13 13:48:54 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "deque.h"

static int	error()
{
	write(2, "Error\n", 6);
	return (1);
}



// 다 정렬 되어있으면 프로그램 바로 끝내기 
int main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;
	char	**input;

	if (argc < 2)
		return (error());
	input = parse_input(argc, argv);
	if (input == NULL)
		return (error());
	if (init_deque(&a, &b, input, get_element_count(input)) == FALSE)
		return (error());
	sort_deque(a, b);
	free_deque(a);
	free_deque(b);
	return (0);
}
