/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:48 by trischma          #+#    #+#             */
/*   Updated: 2024/07/25 12:22:49 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_back(t_stack *a, t_stack *b, t_values *values)
{
	values->i = 0;
	while (b->size > 0)
		pa(a, b);
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
