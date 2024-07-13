#include "../include/push_swap.h"

void	how_many(t_stack *a, t_stack *b)
{
	if (a->size > 10)
		organize_more(a, b);
	else
		organize_less(a, b);
}

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
	how_many(&a, &b);
	return (freeing(&a, &b, splited), 0);
}
