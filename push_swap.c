/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:34:32 by trischma          #+#    #+#             */
/*   Updated: 2024/06/24 13:28:51 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	if (b->size != 0)
		return (0);
	return (1);
}

void organize(t_stack *a, t_stack *b)
{
	int i;
	int tmp;
	int pos;

	while (!is_sorted(a, b))
	{
		while (a->size > 3)
		{
			i = 1;
			tmp = a->arr[0];
			pos = 0;
			while (i < a->size)
			{
				if (a->arr[i] < tmp)
				{
					tmp = a->arr[i];
					pos = i;
				}
				i++;
			}
			if (pos >= a->size / 2)
			{
				while (pos < a->size)
				{
					rra(a);
					pos++;
				}
			}
			else
			{
				while (pos > 0)
				{
					rra(a);
					pos--;
				}
			}
			pb(a, b);
		}
		if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2] && a->arr[1] > a->arr[2])
		{
			sa(a);
			ra(a);
		}
		else if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2] && a->arr[1] < a->arr[2])
		{
			ra(a);
		}
		else if (a->arr[0] > a->arr[1] && a->arr[0] < a->arr[2] && a->arr[1] < a->arr[2])
		{
			sa(a);
		}
		else if (a->arr[0] < a->arr[1] && a->arr[0] < a->arr[2] && a->arr[1] > a->arr[2])
		{
			sa(a);
			ra(a);
		}
		else if (a->arr[0] < a->arr[1] && a->arr[0] > a->arr[2] && a->arr[1] > a->arr[2])
		{
			rra(a);
		}
		while (b->size > 0)
		{
			pa(a, b);
		}
	}
}


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
	i = 0;
	while (a.size > i)
		printf("%d\n", a.arr[i++]);
	return (freeing(&a, &b, splited), 0);
}
