#include "deque.h"
#include "bool.h"
#include "command.h"
#include <stdio.h>

void	print_dq(t_deque *dq)
{
	printf("------- deque body --------\n");
	while (!dq->deque_empty(dq))
	{
		printf("dq : %d\n", dq->peek_back(dq));
		dq->pop_back(dq);
	}
}

static void	merge_sort(t_deque *a, t_deque *b, int size)
{
	if (size == 1)
		return ;
	
	merge_sort(a, b, size / 2);
}

void	sort_deque(t_deque *a, t_deque *b)
{
	int	size;

	size = a->cur_size;
	merge_sort(a, b, size);
}
