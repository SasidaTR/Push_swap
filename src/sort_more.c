/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:35:17 by trischma          #+#    #+#             */
/*   Updated: 2024/06/26 16:28:24 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_min_from_a(t_stack *a, t_stack *b, int posA, int posB)
{
	if (posA > a->size / 2)
	{
		while (posA < a->size)
		{
			rra(a);
			posA++;
		}
	}
	else
	{
		while (posA > 0)
		{
			ra(a);
			posA--;
		}
	}
	if (posB > b->size / 2)
	{
		while (posB < b->size)
		{
			rrb(b);
			posB++;
		}
	}
	else
	{
		while (posB > 0)
		{
			rb(b);
			posB--;
		}
	}
	pb(a, b);
}

void	find_value(t_stack *a, t_stack *b, int *posA, int *posB)
{
	int i = 0;
	int j;

	while (i < a->size)
	{
		j = 0;
		while (j < b->size)
		{
			if ((b->arr[j] > a->arr[i] && b->arr[(j + 1) % b->size] < a->arr[i]) ||
				(b->arr[j] > a->arr[i] && j == b->size - 1))
			{
				*posA = i;
				*posB = (j + 1) % b->size;
				return;
			}
			j++;
		}
		i++;
	}
	*posA = 0;
	*posB = 0;
}

void	organize_more(t_stack *a, t_stack *b)
{
	int i;
	int	posA;
	int	posB;

	i = 1;
	posA = 0;
	posB = 0;
	while (i < a->size)
	{
		if (a->arr[i] < a->arr[posA])
			posA = i;
		i++;
	}
	push_min_from_a(a, b, posA, posB);
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] > a->arr[posA])
			posA = i;
		i++;
	}
	push_min_from_a(a, b, posA, posB);
	while (a->size > 0)
	{
		find_value(a, b, &posA, &posB);
		push_min_from_a(a, b, posA, posB);
	}
	while (b->size > 0)
		pa(a, b);
	while (!is_sorted(a, b))
		rra(a);
}
