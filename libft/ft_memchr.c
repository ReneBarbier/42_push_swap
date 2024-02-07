/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:40:55 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/18 15:11:00 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n > 0)
	{
		if (*ptr == (unsigned char) c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (0);
}
/*
int main ()
{
	const char *str = "hol\0 que tal estas";
	printf("%s\n", ft_memchr(str, 'a', 6));
	printf("%s", memchr(str, 'a', 6));
}
*/