#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include "deque.h"

t_bool	init_deque(t_deque **a, t_deque **b, char **input, size_t element_size);
size_t	get_element_count(char **split);
char	**parse_input(int argc, char **argv);
void	*free_deque(t_deque *deque);
void	sort_deque(t_deque *a, t_deque *b);

#endif
