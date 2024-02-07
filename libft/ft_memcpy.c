/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:45:43 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/18 13:20:17 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
/*
int main ()
{
	const char src[] = "hola que tal estas";
	char dst[] = "123456789";
	const char src1[] = "hola que tal estas";
	char dst1[] = "123456789";

	ft_memcpy(NULL, NULL, 4);	
	memcpy(NULL, NULL, 4);
	printf("%s\n", dst);
	printf("%s", dst1);
}*/
