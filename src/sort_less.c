/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:49:31 by trischma          #+#    #+#             */
/*   Updated: 2024/06/25 15:43:19 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_rest(t_stack *a, t_stack *b)
{
	if (a->size == 3)
	{
		if (a->arr[0] > a->arr[1] && a->arr[1] > a->arr[2])
		{
			sa(a);
			rra(a);
		}
		else if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2])
			ra(a);
		else if (a->arr[0] > a->arr[1])
			sa(a);
		else if (a->arr[1] > a->arr[2])
		{
			sa(a);
			ra(a);
		}
		else if (a->arr[0] < a->arr[2] && a->arr[1] > a->arr[2])
			rra(a);
	}
	else if (a->size == 2 && a->arr[0] > a->arr[1])
		sa(a);
	while (b->size > 0)
		pa(a, b);
}

void	push_min_to_b(t_stack *a, t_stack *b, int pos)
{
	if (pos > a->size / 2)
	{
		while (pos < a->size)
		{
			rra(a);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	pb(a, b);
}

int	is_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	if (b->size != 0)
		return (0);
	return (1);
}

void	organize_less(t_stack *a, t_stack *b)
{
	int	i;
	int	pos;

	while (!is_sorted(a, b))
	{
		while (a->size > 3)
		{
			i = 1;
			pos = 0;
			while (i < a->size)
			{
				if (a->arr[i] < a->arr[pos])
					pos = i;
				i++;
			}
			push_min_to_b(a, b, pos);
		}
		sort_rest(a, b);
	}
}
