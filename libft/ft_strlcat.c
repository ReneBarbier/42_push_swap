/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:42:47 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/18 15:23:53 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	full_size;

	i = 0;
	j = 0;
	full_size = 0;
	while (dst[i] != '\0')
		i++;
	while (src[full_size] != '\0')
		full_size++;
	if (size <= i)
		full_size += size;
	else
		full_size += i;
	if (size == 0)
		return (full_size);
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (full_size);
}
/*
int main ()
{
	char dst[11] = "a";
	char dst1[11] = "a";
	const char src[] = "lorem";
	size_t total_size = 15; //sizeof(dst1); 
	printf("%lu\n", ft_strlcat(dst, src, total_size));
	printf("%lu\n", strlcat(dst1, src, total_size));
	printf("%s\n%s", dst, dst1);
}*/