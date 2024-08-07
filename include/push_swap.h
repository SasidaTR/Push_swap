/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:23:11 by trischma          #+#    #+#             */
/*   Updated: 2024/07/25 12:23:12 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_values
{
	int	min;
	int	max;
	int	posa;
	int	posb;
	int	i;
	int	j;
	int	k;
}	t_values;

typedef struct s_stack
{
	int	*arr;
	int	size;
}	t_stack;

// libft
int		ft_atoi(const char *str);
int		ft_isdigit(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(int argc, char **argv);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

// utils
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// src
void	organize_less(t_stack *a, t_stack *b);
void	organize_more(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a, t_stack *b);
void	sort_rest(t_stack *a, t_stack *b);

void	find_min_n_max(t_stack *b, t_values *values);
void	get_in_line(t_stack *ab, int posab, int x);
void	push_back(t_stack *a, t_stack *b, t_values *values);
void	find_value(t_stack *a, t_stack *b, t_values *values);
#endif