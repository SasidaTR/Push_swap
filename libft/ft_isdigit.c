/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:30:13 by trischma          #+#    #+#             */
/*   Updated: 2024/06/25 11:46:09 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isdigit(const char *str)
{
	int	result;
	int	temp;

	if (*str == '+' || *str == '-')
		str++;
	result = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		temp = result;
		result = result * 10 + (*str - '0');
		if (result != -2147483648 && result / 10 != temp)
			return (0);
		if (result != -2147483648 && result < 0)
			return (0);
		str++;
	}
	return (1);
}
