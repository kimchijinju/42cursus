#include "deque.h"
#include "bool.h"
#include "command.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/wait.h>

void	print_dq(t_deque *dq)
{
	printf("------- deque body --------\n");
	while (!dq->deque_empty(dq))
	{
		int peek = dq->peek_back(dq);
		printf("[");
		for(int i = 0; i < peek; i++)
		{
			printf("-");
		}
		printf("]  %d \n", peek);
		dq->pop_back(dq);
	}
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	temp;
	t_bool	swaped;

	swaped = TRUE;
	while (swaped)
	{
		i = 0;
		swaped = FALSE;
		while(i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swaped = TRUE;
			}
			i++;
		}
	}
}

void	array_copy(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	get_pivot(t_deque *a, int *pivot1, int *pivot2)
{
	int	*arr;

	arr = malloc(sizeof(int) * a->max_size);
	if (!arr)
		return ;
	array_copy(arr, a->arr, a->max_size);
	bubble_sort(arr, a->max_size);
	*pivot1 = arr[a->max_size / 3];
	*pivot2 = arr[(a->max_size / 3) * 2];
	free(arr);
}

void	partitioning(t_deque *a, t_deque *b, int pivot1, int pivot2)
{
	int	peek;
	int	count;
	
	count = 0;
	while (count < a->max_size)
	{
		peek = a->peek_back(a);
		if (peek < pivot2 && peek >= pivot1)
			pb(a,b);
		else if (peek < pivot1)
		{
			pb(a, b);
			rb(b);
		}
		else
			ra(a);
		count++;
	}
	while (!a->deque_empty(a))
		pb(a,b);
}

int	get_rotate_count(t_deque *a, int b_value)
{
	int	count;
	int	a_value;

	count = 0;
	while (count < a->cur_size)
	{
		a_value = a->arr[(a->back - count + a->max_size) % a->max_size];
		if (b_value < a_value)
			break;
		count++;
	}
	if (count > a->cur_size / 2)
		count = (a->cur_size - count) * -1;
	return (count);
}

void	sort_from_b_to_a(t_deque *a, t_deque *b)
{
	int	count;
	int	b_value;
	int	a_rotate_count;
	int	b_rotate_count;

	count = 0;
	while (count < b->cur_size)
	{
		b_value = b->arr[(b->front + count) % b->max_size];
		a_rotate_count = get_rotate_count(a, b_value);
		b_rotate_count = count;
		if (b_rotate_count > b->cur_szie / 2)
			b_rotate_count = (b->cur_size - b_rotate_count) * -1;
		count++;
	}
}

void	sort_deque(t_deque *a, t_deque *b)
{
	int	size;
	int	pivot1;
	int	pivot2;

	size = a->cur_size;
	get_pivot(a, &pivot1, &pivot2);
	printf("pv1 : %d pv2 : %d ", pivot1, pivot2);
	partitioning(a, b, pivot1, pivot2);
	sort_from_b_to_a(a, b);
	print_dq(b);
}
