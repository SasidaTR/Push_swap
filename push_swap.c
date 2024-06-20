/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:34:32 by trischma          #+#    #+#             */
/*   Updated: 2024/06/20 11:09:53 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int	i;
	int	pushed;

	pushed = 0;
	i = a->size;
	while (i > 0)
	{
		if (a->arr[0] >= min && a->arr[0] <= max)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i--;
	}
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		int max_index = 0;
		for (int i = 1; i < b->size; i++)
		{
			if (b->arr[i] > b->arr[max_index])
				max_index = i;
		}
		if (max_index <= b->size / 2)
		{
			while (max_index-- > 0)
				rb(b);
		}
		else
		{
			max_index = b->size - max_index;
			while (max_index-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	organize(t_stack *a, t_stack *b)
{
	int	chunk_size = 20;
	int min = 0;
	int max = chunk_size;

	while (a->size > 0)
	{
		push_min_to_b(a, b, min, max);
		min += chunk_size;
		max += chunk_size;
	}
	move_back_to_a(a, b);
}


// void	organize(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	tmp;

// 	while (a->size != 0)
// 	{
// 		i = 1;
// 		tmp = a->arr[0];
// 		while (i < a->size)
// 		{
// 			if (tmp > a->arr[i])
// 				tmp = a->arr[i];
// 			i++;
// 		}
// 		while (tmp != a->arr[0])
// 			ra(a);
// 		pb(a, b);
// 	}
// 	while (b->size != 0)
// 		pa(a, b);
// }

// void	organize(t_stack *a, t_stack *b)
// {
// 	int	min_index;
// 	int	i;

// 	while (a->size > 0)
// 	{
// 		min_index = 0;
// 		i = 0;
// 		while (i < a->size)
// 		{
// 			if (a->arr[i] < a->arr[min_index])
// 				min_index = i;
// 			i++;
// 		}
// 		if (min_index <= a->size / 2)
// 			while (min_index-- > 0)
// 				ra(a);
// 		else
// 		{
// 			min_index = a->size - min_index;
// 			while (min_index-- > 0)
// 				rra(a);
// 		}
// 		pb(a, b);
// 	}
// 	while (b->size > 0)
// 		pa(a, b);
// }

int	checker(t_stack *a, char **splited, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < i)
	{
		if (!ft_isdigit(splited[j]))
			return (0);
		a->arr[j] = ft_atoi(splited[j]);
		j++;
	}
	j = 0;
	while (j < i - 1)
	{
		k = j + 1;
		while (k < i)
		{
			if (a->arr[j] == a->arr[k])
				return (0);
			k++;
		}
		j++;
	}
	return (1);
}

int	prep(t_stack *a, t_stack *b, int i)
{
	a->arr = (int *)malloc(i * sizeof(int));
	b->arr = (int *)malloc(i * sizeof(int));
	if (!a->arr || !b->arr)
		return (0);
	a->size = i;
	b->size = 0;
	return (1);
}

void	freeing(t_stack *a, t_stack *b, char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
	free(a->arr);
	free(b->arr);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*joined;
	char	**splited;
	int		i;

	if (argc < 2)
		return (1);
	joined = ft_strjoin(argc, argv);
	if (!joined)
		return (write(1, "Error\n", 6), 1);
	splited = ft_split(joined, ' ');
	free(joined);
	if (!splited)
		return (write(1, "Error\n", 6), 1);
	i = 0;
	while (splited[i])
		i++;
	if (!prep(&a, &b, i))
		return (write(1, "Error\n", 6), freeing(&a, &b, splited), 1);
	if (!checker(&a, splited, i))
		return (write(1, "Error\n", 6), freeing(&a, &b, splited), 1);
	organize(&a, &b);
	return (freeing(&a, &b, splited), 0);
}
