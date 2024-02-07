/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:07:31 by rbarbier          #+#    #+#             */
/*   Updated: 2023/10/20 12:46:36 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i++;
	}
	if ((string[i]) == (char)c)
		return ((char *)&string[i]);
	return (NULL);
}

void	*ft_clean_up(char **alloc_mem, int extra, char **buff)
{
	if (extra == 1)
	{
		if (buff && *buff)
		{
			free(*buff);
			*buff = NULL;
		}
	}
	if (alloc_mem && *alloc_mem)
	{
		free(*alloc_mem);
		*alloc_mem = NULL;
	}
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	int		i;
	int		j;
	size_t	len;
	char	*new_storage;

	if (storage == NULL)
	{
		storage = malloc(sizeof(char) * 1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	len = ft_strlen(storage);
	new_storage = malloc(sizeof(char) * (ft_strlen(buffer) + len + 1));
	if (!new_storage)
		return (ft_clean_up(&storage, 0, &storage));
	i = -1;
	while (storage[++i])
		new_storage[i] = storage[i];
	j = 0;
	while (buffer[j])
		new_storage[i++] = buffer[j++];
	new_storage[i] = '\0';
	ft_clean_up(&storage, 0, &storage);
	return (new_storage);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub_s;
	unsigned long long	j;
	unsigned long long	i;

	if (start > (unsigned int) ft_strlen(s))
	{
		return (NULL);
	}
	if ((unsigned long) ft_strlen(s) - start < len)
		sub_s = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		sub_s = malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			sub_s[j++] = s[i];
		i++;
	}
	sub_s[j] = '\0';
	return (sub_s);
}
