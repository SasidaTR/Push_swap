/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:35:17 by trischma          #+#    #+#             */
/*   Updated: 2024/06/26 17:38:11 by trischma         ###   ########.fr       */
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

void	find_value(t_stack *a, t_stack *b, int *posa, int *posb)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < b->size)
		{
			if ((b->arr[j] > a->arr[i] && b->arr[(j + 1) % b->size] < a->arr[i])
				|| (b->arr[j] > a->arr[i] && j == b->size - 1))
			{
				*posa = i;
				*posb = (j + 1) % b->size;
				return ;
			}
			j++;
		}
		i++;
	}
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
	while (a->size > 0)
	{
		find_value(a, b, &posa, &posb);
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
