/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:44:14 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/20 12:46:35 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != (char)c)
	{
		if (i == 0)
			return (NULL);
		else
			i--;
	}
	return ((char *)&str[i]);
}
/*
int	main(void)
{
	const char	*str = "hola que tal estas";
	printf("%s", strrchr(str, 'a'));
}*/
//warning error