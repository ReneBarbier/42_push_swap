/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:27:58 by rbarbier          #+#    #+#             */
/*   Updated: 2023/09/25 15:44:30 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	*ft_word_slicer(int start, int end, char const *s)
{
	char	*sliced_word;
	int		i;

	sliced_word = malloc(sizeof(char) * (end - start + 1));
	if (!sliced_word)
		return (NULL);
	i = 0;
	while (start < end)
		sliced_word[i++] = s[start++];
	sliced_word[i] = '\0';
	return (sliced_word);
}
/*
int	check(char const *s, char c)
{
	int	flag;

	flag = 0;
	while (*s)
	{
		if (c == *s)
			flag = 1;
		s++;
	}
	return (flag);
}*/

void	ft_free(char **split, int j)
{
	while (j-- > 0)
		free(split[j]);
	free(split);
}

int	ft_size_word(char const *s, int i, char c)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	char	**split;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, i, c);
		split[j] = ft_substr(s, i, size);
		if (!split[j++])
		{
			ft_free(split, j - 1);
			return (NULL);
		}
		i += size;
	}
	split[j] = 0;
	return (split);
}
/*
#include <stdio.h>
int main()
{
	char const s[] = "   lorem   ipsum dolor     
	sit amet, consectetur   adipiscing elit. Sed non risus. 
	Suspendisse   ";
	char c = ' ';
	char **str;
	int i = 0;

	str = ft_split(s, c);
	while (i < 16)
	{
		printf("%s\n", str[i]);
		i++;
	}
}*/
