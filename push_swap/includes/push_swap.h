/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:19:23 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 14:29:07 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stddef.h"
# include "bool.h"
# include "deque.h"

typedef struct s_min_rotate_count
{
	int	a;
	int	b;
}	t_min_rotate_count;

t_bool				duplicate_input(int *arr, size_t arr_size);
t_bool				wrong_input(char *str);
t_bool				is_incorrect_string(char *str);
t_bool				integer_range_out(char *str);
t_bool				init_deque(t_deque **a, t_deque **b, char **input);
t_deque				*create_deque_and_fill_array(char **input,
						size_t element_size);
char				**parse_input(int argc, char **argv);
t_bool				input_sorted(t_deque *a);
void				*free_deque(t_deque *deque);
void				sort_deque(t_deque *a, t_deque *b);
void				sort_from_b_to_a(t_deque *a, t_deque *b);
void				partitioning(t_deque *a, t_deque *b);
t_min_rotate_count	get_best_location(t_deque *a, t_deque *b);
void				sort_three_elem(t_deque *a);
int					ft_abs(int n);
#endif
