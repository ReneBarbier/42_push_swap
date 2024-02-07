/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:46:09 by rbarbier          #+#    #+#             */
/*   Updated: 2024/01/13 13:30:18 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define MAX_BUFFER_SIZE 1000

//utilizar buffer??
void	*ft_memmove(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	buffer[MAX_BUFFER_SIZE];

	if (dst == NULL && src == NULL)
		return (dst);
	if (len > MAX_BUFFER_SIZE)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buffer[i] = src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst[i] = buffer[i];
		i++;
	}
	return (dst);
}
/*
int main ()
{
	const char src[] = "hola que tal";
	char dst[] = "12345";
	const char src1[] = "hola que tal";
	char dst1[] = "12345";

	ft_memmove(dst, src, 9);
	memmove(dst1, src1, 9);
	printf("%s\n", dst);
	printf("%s", dst1);
}
*/