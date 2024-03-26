/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:16:13 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/26 21:59:41 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char const *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char const *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, const char *s2);
char	*get_next_line(int fd);

#endif
