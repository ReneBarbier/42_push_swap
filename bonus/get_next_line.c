/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:08:16 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/07 16:18:48 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_read(char *storage, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_clean_up(&storage, 0, &storage));
	buffer[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_clean_up(&storage, 1, &buffer));
		else if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	return (storage);
}

char	*ft_extract(char *storage)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!storage || !storage[0])
		return (NULL);
	while (storage[i] != '\n' && storage[i])
		i++;
	if (storage[i] == '\n')
		i++;
	tmp = ft_substr(storage, 0, i);
	return (tmp);
}

char	*ft_update_storage(char	*storage)
{
	int		i;
	int		j;
	int		len;
	char	*new_storage;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	if (storage[i] == '\0')
		return (ft_clean_up(&storage, 0, &storage));
	i++;
	len = ft_strlen(storage);
	new_storage = malloc(sizeof(char) * (len - i) + 1);
	if (!new_storage)
		return (ft_clean_up(&storage, 0, &storage));
	j = 0;
	while (storage[i] != '\0')
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;
	int			found_line;

	found_line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_clean_up(&storage, 0, &storage));
	storage = ft_read(storage, fd);
	if (!storage)
		return (ft_clean_up(&storage, 0, &storage));
	line = ft_extract(storage);
	if (!line)
		return (ft_clean_up(&storage, 0, &storage));
	storage = ft_update_storage(storage);
	return (line);
}
