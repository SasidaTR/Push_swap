/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:35:17 by trischma          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:39 by trischma         ###   ########.fr       */
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

void	min_n_max(t_stack *b, t_values *values)
{
	int	j;
	int	k;

	j = 0;
	values->min = 0;
	while (++j < b->size)
		if (b->arr[values->min] > b->arr[j])
			values->min = j;
	k = 0;
	values->max = 0;
	while (++k < b->size)
		if (b->arr[values->max] < b->arr[k])
			values->max = k;
}

void	find_value(t_stack *a, t_stack *b, t_values *values)
{
	int	i;
	int	j;
	int	k;

	min_n_max(b, values);
	i = 0;
	while (i <= a->size / 2)
	{
		j = a->size - i;
		while (j < a->size + i)
		{
			k = b->size - i;
			while (k < b->size + i)
			{
				if (a->arr[j % a->size] < b->arr[values->min % b->size])
				{
					values->posa = j % a->size;
					values->posb = (values->min + 1) % b->size;
					return ;
				}
				if (a->arr[j % a->size] > b->arr[values->max % b->size])
				{
					values->posa = j % a->size;
					values->posb = values->max % b->size;
					return ;
				}
				if (b->arr[k % b->size] > a->arr[j % a->size]
					&& b->arr[(k + 1) % b->size] < a->arr[j % a->size])
				{
					values->posa = j % a->size;
					values->posb = (k + 1) % b->size;
					return ;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	otherwise(a, b, values);
}

void	organize_more(t_stack *a, t_stack *b)
{
	t_values values;
	int	i;

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
	while (b->size > 0)
		pa(a, b);
	i = 0;
	while (a->arr[i] > a->arr[i + 1])
		i++;
	while (!is_sorted(a, b))
		if (i < a->size / 2)
			ra(a);
	else
		rra(a);
}
