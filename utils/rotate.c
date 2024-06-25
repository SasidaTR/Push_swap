/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:43:08 by trischma          #+#    #+#             */
/*   Updated: 2024/06/25 11:46:36 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->arr[0];
	i = 0;
	while (++i < a->size)
		a->arr[i - 1] = a->arr[i];
	a->arr[a->size - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->arr[0];
	i = 0;
	while (++i < b->size)
		b->arr[i - 1] = b->arr[i];
	b->arr[b->size - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
