/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:58:17 by trischma          #+#    #+#             */
/*   Updated: 2024/06/25 11:46:39 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->arr[a->size - 1];
	i = a->size;
	while (--i > 0)
		a->arr[i] = a->arr[i - 1];
	a->arr[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->arr[b->size - 1];
	i = b->size;
	while (--i > 0)
		b->arr[i] = b->arr[i - 1];
	b->arr[0] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
