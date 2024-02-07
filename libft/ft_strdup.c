/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:19:15 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/20 15:04:59 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*d_str;

	i = ft_strlen(str);
	d_str = (void *)malloc(sizeof(char) * (i + 1));
	if (!d_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		d_str[i] = str[i];
		i++;
	}
	d_str[i] = '\0';
	return (d_str);
}
/*
#include <stdio.h>
int	main()
{
	const char str[] = "hola que tal estas";

	printf("%s\n", ft_strdup(str));
	printf("%s", strdup(str));
}*/
