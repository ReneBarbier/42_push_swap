/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:51:11 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/21 11:07:27 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*new_s;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new_s = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, size_s1 + 1);
	ft_strlcat(new_s, s2, size_s2 + size_s1 + 1);
	return (new_s);
}
/*
#include <stdio.h>
int main()
{
	const char s1[] = "hola que";
	const char s2[] = "tal estas";
	printf("%s\n", ft_strjoin(s1, s2));
}*/