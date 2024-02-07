/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:50:59 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 11:29:11 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

char	*ft_make_str(unsigned long n, int *len)
{
	int		i;
	char	*str;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	str = ft_calloc(i, sizeof(char));
	*len = i - 1;
	return (str);
}

int	ft_extra(int i, unsigned long ptr, char *output)
{
	char	base[16];
	int		j;
	int		tmp;

	ft_get_base(base, 0);
	j = i;
	while (ptr != 0)
	{
		output[i--] = ptr % 16;
		ptr /= 16;
	}
	while (++i <= j)
	{
		tmp = base[(int)output[i]];
		if (write(1, &tmp, 1) == -1)
			return (-1);
	}
	return (1);
}

int	ft_print_ptr(unsigned long ptr)
{
	char	*output;
	int		count;
	int		i;

	i = 0;
	count = ft_print_str("0x");
	if (count == -1)
		return (-1);
	if (ptr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (3);
	}
	output = ft_make_str(ptr, &i);
	if (!output)
		return (0);
	count += i + 1;
	if (ft_extra(i, ptr, output) == -1)
		return (-1);
	free(output);
	return (count);
}
