#include "deque.h"
#include "bool.h"
#include "command.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	print_dq(t_deque *dq)
{
	printf("------- deque body --------\n");
	int j;

	j = 0;
	while (j < dq->cur_size)
	{
		int peek = dq->peek_back_index(dq, j);
		printf("[");
		for(int i = 0; i < peek; i++)
		{
			printf("-");
		}
		printf("]  %d \n", peek);
		j++;
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

static void	array_copy(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	get_pivot(t_deque *a, int *pivot1, int *pivot2)
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

static void	partitioning(t_deque *a, t_deque *b, int pivot1, int pivot2)
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

static int	judge_forward_reverse(t_deque *deque, int count)
{
	if (count > deque->cur_size / 2)
		count = (count / 2) * -1;
	return (count);
}

static int	get_a_rotate_count(t_deque *a, int b_value)
{
	int	count;
	int	a_min;
	
	b_value = 0;
	a_min = a->peek_back(a);
	count = get_min_value_index(a);
//	while (count < a->cur_size)
//	{
//		a_value = a->peek_back_index(a, count);
//		if (b_value < a_value)
//			break;
//		count++;
//	}
	count = judge_forward_reverse(a, count);
	return (count);
}

typedef struct s_min_rotate_count
{
	int	a;
	int	b;
}	t_min_rotate_count;

static t_min_rotate_count	sort_from_b_to_a(t_deque *a, t_deque *b)
{
	int	count;
	int	b_value;
	int	a_rotate_count;
	int	b_rotate_count;
	t_min_rotate_count min;

	count = 0;
	min.a = a->cur_size;
	min.b = b->cur_size;
	while (count < b->cur_size)
	{
		b_value = b->peek_back_index(b, count);
		a_rotate_count = get_a_rotate_count(a, b_value);
		b_rotate_count = judge_forward_reverse(b, count);
		//printf("a_ro : %d , b_ro : %d\n", a_rotate_count, b_rotate_count);
		if (abs(a_rotate_count) + abs(b_rotate_count) < abs(min.a) + abs(min.b))
		{
			min.a =  a_rotate_count;
			min.b =  b_rotate_count;
		}
		count++;
	}
	return min;
}

void	sort_deque(t_deque *a, t_deque *b)
{
	int	size;
	int	pivot1;
	int	pivot2;
	t_min_rotate_count min;

	size = a->cur_size;
	get_pivot(a, &pivot1, &pivot2);
	partitioning(a, b, pivot1, pivot2);
	while (!b->deque_empty(b))
	{
		min = sort_from_b_to_a(a, b);
		while (min.b < 0)
		{
			rrb(b);
			min.b++;
		}
		while (min.b > 0)
		{
			rb(b);
			min.b--;
		}
		while (min.a < 0)
		{
			rra(a);
			min.a++;
		}
		while (min.a > 0)
		{
			ra(a);
			min.a--;
		}
		pa(a, b);
	}
	print_dq(a);
}
