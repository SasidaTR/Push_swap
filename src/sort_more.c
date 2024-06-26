/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:35:17 by trischma          #+#    #+#             */
/*   Updated: 2024/06/26 15:13:29 by trischma         ###   ########.fr       */
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
	int	i;
	int	j;
	int k;
	int l;

	i = -5;
	while (i < 4 || i + 5 > a->size)
	{
		if (a->size < 10)
			k = i + 5;
		else if (i <= 0)
			k = a->size + i;
		else
			k = i;
		j = -5;
		while (j < 4 || j + 5 < b->size)
		{
			if (b->size < 10)
				l = j + 5;
			else if (j <= 0)
				l = b->size + j;
			else
				l = j;
			if (a->arr[k] > b->arr[b->size] && a->arr[k] < b->arr[0])
			{
				*posA = k;
				*posB = 0;
				return ;
			}
			if (a->arr[k] > b->arr[l - 1] && a->arr[k] < b->arr[l])
			{
				*posA = k;
				*posB = l;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	organize_more(t_stack *a, t_stack *b)
{
	int	posA;
	int	posB;

	posA = 0;
	posB = 0;
	pb(a, b);
	pb(a, b);
	if (b->arr[0] < b->arr[1])
		sb(b);
	while (a->size > 0)
	{
		find_value(a, b, &posA, &posB);
		printf("posA: %d, posB: %d\n", posA, posB);
		push_min_from_a(a, b, posA, posB);
	}
	while (b->size > 0)
		pa(a, b);
}
