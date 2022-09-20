/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:03:03 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 09:03:04 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include <unistd.h>
# include "deque.h"

void	sa(t_deque *a);
void	sb(t_deque *a);
void	ss(t_deque *a, t_deque *b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	ra(t_deque *deque);
void	rb(t_deque *deque);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *deque);
void	rrb(t_deque *deque);
void	rrr(t_deque *a, t_deque *b);

#endif
