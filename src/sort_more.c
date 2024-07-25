/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:41 by trischma          #+#    #+#             */
/*   Updated: 2024/07/25 12:22:42 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	otherwise(t_stack *a, t_stack *b, t_values *values)
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
				values->posa = j % a->size;
				values->posb = (k + 1) % b->size;
				return ;
			}
			k++;
		}
	}
}

int	what_if(t_stack *a, t_stack *b, t_values *values)
{
	if (a->arr[values->j % a->size] < b->arr[values->min % b->size])
	{
		values->posa = values->j % a->size;
		values->posb = (values->min + 1) % b->size;
		return (1);
	}
	if (a->arr[values->j % a->size] > b->arr[values->max % b->size])
	{
		values->posa = values->j % a->size;
		values->posb = values->max % b->size;
		return (1);
	}
	if (b->arr[values->k % b->size] > a->arr[values->j % a->size]
		&& b->arr[(values->k + 1) % b->size] < a->arr[values->j % a->size])
	{
		values->posa = values->j % a->size;
		values->posb = (values->k + 1) % b->size;
		return (1);
	}
	return (0);
}

void	find_value(t_stack *a, t_stack *b, t_values *values)
{
	find_min_n_max(b, values);
	values->i = 0;
	while (values->i <= a->size / 2)
	{
		values->j = a->size - values->i;
		while (values->j < a->size + values->i)
		{
			values->k = b->size - values->i;
			while (values->k < b->size + values->i)
			{
				if (what_if(a, b, values))
					return ;
				values->k++;
			}
			values->j++;
		}
		values->i++;
	}
	otherwise(a, b, values);
}

void	organize_more(t_stack *a, t_stack *b)
{
	t_values	values;
	int			i;

	pb(a, b);
	pb(a, b);
	if (b->arr[0] < b->arr[1])
		sb(b);
	while (a->size > 0)
	{
		find_value(a, b, &values);
		get_in_line(a, values.posa, 1);
		get_in_line(b, values.posb, 2);
		pb(a, b);
	}
	push_back(a, b, &values);
	i = 0;
	while (a->arr[i] > a->arr[i + 1])
		i++;
	while (!is_sorted(a, b))
	{
		if (i < a->size / 2)
			ra(a);
		else
			rra(a);
	}
}
