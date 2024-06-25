/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:38:27 by trischma          #+#    #+#             */
/*   Updated: 2024/06/25 17:47:30 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_min_from_a(t_stack *a, t_stack *b, t_pos *pos)
{
	if (pos->posA > a->size / 2)
	{
		while (pos->posA < a->size)
		{
			rra(a);
			pos->posA++;
		}
	}
	else
	{
		while (pos->posA > 0)
		{
			ra(a);
			pos->posA--;
		}
	}
	if (pos->posB > b->size / 2)
	{
		while (pos->posB < b->size)
		{
			rrb(b);
			pos->posB++;
		}
	}
	else
	{
		while (pos->posB > 0)
		{
			rb(b);
			pos->posB--;
		}
	}
	pb(a, b);
	if (b->size > 1 && b->arr[0] > b->arr[1])
		sb(b);
}

	t_pos	find_value(t_stack *a, t_stack *b)
	{
		t_pos	pos;
		int		i;
		int		j;

		pos.posA = 0;
		pos.posB = 0;
		i = 0;
		while (i < a->size)
		{
			j = 0;
			while (j < b->size)
			{
				if (a->arr[i] < a->arr[pos.posA] || 
					(a->arr[i] == a->arr[pos.posA] && b->arr[j] < b->arr[pos.posB]))
				{
					pos.posA = i;
					pos.posB = j;
				}
				j++;
			}
			i++;
		}
		return (pos);
	}

void	organize_more(t_stack *a, t_stack *b)
{
	t_pos pos;
	pb(a, b);
	pb(a, b);
	if (b->arr[0] < b->arr[1])
		sb(b);
	while (a->size > 0)
	{
		pos = find_value(a, b);
		push_min_from_a(a, b, &pos);
	}
	while (b->size > 0)
		pa(a, b);
}
