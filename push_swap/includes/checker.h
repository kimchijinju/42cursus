/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:36:09 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 11:36:10 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "stddef.h"
# include "bool.h"
# include "deque.h"

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
t_bool				get_command_and_sort(t_deque *a, t_deque *b);
int					error(void);

#endif
