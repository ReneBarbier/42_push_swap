/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:42:18 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/15 14:13:14 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	find_num(char *str, int i, int digits, int negative)
{
	int		j;
	long	num;
	long	elevate;
	long	iteration;

	j = 0;
	num = 0;
	iteration = digits;
	while (i < digits + i)
	{
		elevate = 1;
		while (j < iteration - 1)
		{
			elevate *= 10;
			j++;
		}
		num += (str[i] - 48) * elevate;
		iteration--;
		digits--;
		j = 0;
		i++;
	}
	if (negative == 1)
		num *= -1;
	return (num);
}

long	ft_atol(char *str)
{
	int		i;
	int		negative;
	int		digits;

	i = 0;
	digits = 0;
	negative = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		negative = 1;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		digits++;
		i++;
	}
	if (digits == 0)
		return (0);
	i -= digits;
	return (find_num(str, i, digits, negative));
}
