/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:38:27 by trischma          #+#    #+#             */
/*   Updated: 2024/06/25 16:52:01 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_min_to_b(t_stack *a, t_stack *b, t_pos *pos)
{
	if (pos->posA > a->size / 2)
	{
		while (pos->posA < a->size)
		{
			rra(a);
			pos++;
		}
	}
	else
	{
		while (pos->posA > 0)
		{
			ra(a);
			pos--;
		}
	}
	if (pos->posB > a->size / 2)
	{
		while (pos->posA < a->size)
		{
			rrb(b);
			pos++;
		}
	}
	else
	{
		while (pos->posB > 0)
		{
			rb(b);
			pos--;
		}
	}
	pb(a, b);
}

t_pos	*find_value(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	t_pos	pos;

	pos.posA = 0;
	pos.posB = 0;
	i = 0;
	while (i < 5 && i < a->size)
	{
		j = 0;
		while (j < 5 && j < b->size)
		{
			if (a->arr[i] - b->arr[j] < a->arr[pos.posA] - b->arr[pos.posB])
			{
				pos.posA = i;
				pos.posB = j;
			}
			j++;
		}
		j = b->size - 5;
		while (j < b->size && j >= 0)
		{
			if (a->arr[i] - b->arr[j] < a->arr[pos.posA] - b->arr[pos.posB])
			{
				pos.posA = i;
				pos.posB = j;
			}
			j++;
		}
		i++;
	}
	i = a->size - 5;
	while (i < a->size && i >= 0)
	{
		j = 0;
		while (j < 5 && j < b->size)
		{
			if (a->arr[i] - b->arr[j] < a->arr[pos.posA] - b->arr[pos.posB])
			{
				pos.posA = i;
				pos.posB = j;
			}
			j++;
		}
		j = b->size - 5;
		while (j < b->size && j >= 0)
		{
			if (a->arr[i] - b->arr[j] < a->arr[pos.posA] - b->arr[pos.posB])
			{
				pos.posA = i;
				pos.posB = j;
			}
			j++;
		}
		i++;
	}
	return (&pos);
}

void	organize_more(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	if (b->arr[0] < b->arr[1])
		rb(b);
	while (a->size > 0)
		push_min_to_b(a, b, find_value(a, b));
	while (b->size > 0)
		pa(a, b);
}
