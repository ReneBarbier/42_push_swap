/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:07:24 by rbarbier          #+#    #+#             */
/*   Updated: 2023/10/20 12:47:42 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_clean_up(char **alloc_mem, int extra, char **buff);
char	*ft_strjoin(char *storage, char *buffer);
char	*ft_strchr(const char *string, int c);
int		ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif
