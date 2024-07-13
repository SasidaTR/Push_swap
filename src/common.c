#include "../include/push_swap.h"

void	otherwisee(t_stack *a, t_stack *b, t_values *values)
{
	int	j;
	int	k;

	j = 0;
	while (j < a->size)
	{
		k = 0;
		while (k < b->size)
		{
			if (b->arr[k % b->size] > a->arr[j % a->size]
				&& b->arr[(k + 1) % b->size] < a->arr[j % a->size])
			{
				values->posb = (j + 1) % a->size;
				values->posa = k % b->size;
				return ;
			}
			k++;
		}
	}
}

int	what_iff(t_stack *a, t_stack *b, t_values *values)
{
	if (a->arr[values->j % a->size] < b->arr[values->min % b->size])
	{
		values->posb = values->j % a->size;
		values->posa = values->min % b->size;
		return (1);
	}
	if (a->arr[values->j % a->size] > b->arr[values->max % b->size])
	{
		values->posb = values->j % a->size;
		values->posa = (values->max + 1) % b->size;
		return (1);
	}
	if (b->arr[values->k % b->size] > a->arr[values->j % a->size]
		&& b->arr[(values->k + 1) % b->size] < a->arr[values->j % a->size])
	{
		values->posb = values->j % a->size;
		values->posa = values->k % b->size;
		return (1);
	}
	return (0);
}

void	find_valuee(t_stack *a, t_stack *b, t_values *values)
{
	find_min_n_max(a, values);
	values->i = 0;
	while (values->i <= b->size / 2)
	{
		values->j = b->size - values->i;
		while (values->j < b->size + values->i)
		{
			values->k = a->size - values->i;
			while (values->k < a->size + values->i)
			{
				if (what_iff(b, a, values))
					return ;
				values->k++;
			}
			values->j++;
		}
		values->i++;
	}
	otherwisee(b, a, values);
}

void	push_back(t_stack *a, t_stack *b, t_values *values)
{
	while (b->size > 0)
	{
		find_valuee(a, b, values);
		get_in_line(a, values->posa, 1);
		get_in_line(b, values->posb, 2);
		pa(a, b);
	}
}

void	get_in_line(t_stack *x, int posx, int a_or_b)
{
	while (posx != 0)
	{
		if (posx > x->size / 2)
		{
			if (a_or_b == 1)
				rra(x);
			else
				rrb(x);
			posx++;
			if (posx == x->size)
				posx = 0;
		}
		else
		{
			if (a_or_b == 1)
				ra(x);
			else
				rb(x);
			posx--;
		}
	}
}

void	find_min_n_max(t_stack *x, t_values *values)
{
	values->i = 0;
	values->min = 0;
	values->max = 0;
	while (++values->i < x->size)
	{
		if (x->arr[values->min] > x->arr[values->i])
			values->min = values->i;
		if (x->arr[values->max] < x->arr[values->i])
			values->max = values->i;
	}
}
