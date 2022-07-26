/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:26:16 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 11:22:20 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include "bool.h"

typedef struct s_deque	t_deque;

struct s_deque
{
	int		*arr;
	int		front;
	int		back;
	int		cur_size;
	int		max_size;
	t_deque	(*create_deque)(int n);
	void	(*push_front)(t_deque *self, int val);
	void	(*push_back)(t_deque *self, int val);
	void	(*pop_front)(t_deque *self);
	void	(*pop_back)(t_deque *self);
	int		(*peek_front)(t_deque *self);
	int		(*peek_back)(t_deque *self);
	int		(*peek_back_index)(t_deque *self, int index);
	int		(*get_max_value_index)(t_deque *self);
	int		(*get_min_value_index)(t_deque *self, int target);
	int		(*get_max_value)(t_deque *self);
	int		(*get_min_value)(t_deque *self);
	t_bool	(*deque_empty)(t_deque * self);
	t_bool	(*deque_full)(t_deque * self);
};

t_deque	*create_deque(int n);
void	push_front(t_deque *self, int val);
void	push_back(t_deque *self, int val);
void	pop_front(t_deque *self);
void	pop_back(t_deque *self);
int		peek_front(t_deque *self);
int		peek_back(t_deque *self);
int		peek_back_index(t_deque *self, int index);
t_bool	deque_empty(t_deque *self);
t_bool	deque_full(t_deque *self);
int		get_max_value_index(t_deque *self);
int		get_max_value(t_deque *self);
int		get_min_value_index(t_deque *self, int target);
int		get_min_value(t_deque *self);

#endif
