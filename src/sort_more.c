/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:35:17 by trischma          #+#    #+#             */
/*   Updated: 2024/06/27 12:59:09 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_min_from_a(t_stack *a, t_stack *b, int posa, int posb)
{
	while (posa != 0)
	{
		if (posa > a->size / 2)
		{
			rra(a);
			posa++;
			if (posa == a->size)
				posa = 0;
		}
		else
		{
			ra(a);
			posa--;
		}
	}
	while (posb != 0)
	{
		if (posb > b->size / 2)
		{
			rrb(b);
			posb++;
			if (posb == b->size)
				posb = 0;
		}
		else
		{
			rb(b);
			posb--;
		}
	}
	pb(a, b);
}

int	find_value(t_stack *a, t_stack *b, int *posa, int *posb, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < i && j < a->size)
	{
		k = 0;
		while (k < i && k < b->size)
		{
			if ((b->arr[k] > a->arr[j] && b->arr[(k + 1) % b->size] < a->arr[j])
				|| (b->arr[k] > a->arr[j] && k == b->size - 1))
			{
				*posa = j;
				*posb = (k + 1) % b->size;
				return (1);
			}
			k++;
		}
		j++;
	}
	return (0);
}

void	organize_more(t_stack *a, t_stack *b)
{
	int	i;
	int	posa;
	int	posb;

	i = 0;
	posa = 0;
	posb = 0;
	while (++i < a->size)
		if (a->arr[i] < a->arr[posa])
			posa = i;
	push_min_from_a(a, b, posa, posb);
	i = 0;
	posa = 0;
	while (++i < a->size)
		if (a->arr[i] > a->arr[posa])
			posa = i;
	push_min_from_a(a, b, posa, posb);
	i = 0;
	while (a->size > 0)
	{
		while (!find_value(a, b, &posa, &posb, i))
			i++;
		push_min_from_a(a, b, posa, posb);
	}
	while (b->size > 0)
		pa(a, b);
	i = 0;
	while (a->arr[i] > a->arr[i + 1])
		i++;
	if (i < a->size / 2)
		while (!is_sorted(a, b))
			ra(a);
	else
		while (!is_sorted(a, b))
			rra(a);
}
