/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:09:30 by trischma          #+#    #+#             */
/*   Updated: 2024/06/25 11:46:19 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strjoin(int argc, char **argv)
{
	int		total_len;
	int		i;
	char	*joined_str;
	char	*temp;
	int		arg_len;

	total_len = 0;
	i = 1;
	while (i < argc)
		total_len += ft_strlen(argv[i++]) + 1;
	joined_str = (char *)malloc(total_len * sizeof(char));
	if (!joined_str)
		return (NULL);
	temp = joined_str;
	i = 1;
	while (i < argc)
	{
		arg_len = ft_strlen(argv[i]);
		ft_memcpy(temp, argv[i], arg_len);
		temp += arg_len;
		if (i++ < argc - 1)
			*temp++ = ' ';
	}
	*temp = '\0';
	return (joined_str);
}
