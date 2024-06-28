/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:35:17 by trischma          #+#    #+#             */
/*   Updated: 2024/06/28 15:49:53 by trischma         ###   ########.fr       */
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
	int	min;
	int	max;

	j = 0;
	min = 0;
	while (++j < b->size)
		if (b->arr[min] > b->arr[j])
			min = j;
	k = 0;
	max = 0;
	while (++k < b->size)
		if (b->arr[max] < b->arr[k])
			max = k;
	j = a->size - i;
	while (j < a->size + i)
	{
		k = b->size - i;
		while (k < b->size + i)
		{
			if (a->arr[j % a->size] < b->arr[min % b->size])
			{
				*posa = j % a->size;
				*posb = (min + 1) % b->size;
				return (1);
			}
			if (a->arr[j % a->size] > b->arr[max % b->size])
			{
				*posa = j % a->size;
				*posb = max % b->size;
				return (1);
			}
			if (b->arr[k % b->size] > a->arr[j % a->size]
				&& b->arr[(k + 1) % b->size] < a->arr[j % a->size])
			{
				*posa = j % a->size;
				*posb = (k + 1) % b->size;
				return (1);
			}
			k++;
		}
		j++;
	}
	if (i > a->size / 2)
	{
		j = 0;
		while (j < a->size)
		{
			k = 0;
			while (k < b->size)
			{
				if (b->arr[k % b->size] > a->arr[j % a->size]
					&& b->arr[(k + 1) % b->size] < a->arr[j % a->size])
				{
					*posa = j % a->size;
					*posb = (k + 1) % b->size;
					return (1);
				}
				k++;
			}
		}
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
	pb(a, b);
	pb(a, b);
	if (b->arr[0] < b->arr[1])
		sb(b);
	while (a->size > 0)
	{
		i = 0;
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
