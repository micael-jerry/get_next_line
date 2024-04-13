/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:16:13 by mfidimal          #+#    #+#             */
/*   Updated: 2024/04/13 11:27:51 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef LIMIT_FD_MAX
#  define LIMIT_FD_MAX 1024
# endif

size_t	ft_strlen(char const *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strdup(char const *src);
void	*ft_calloc(size_t count, size_t size);
char	*strjoin_free(char *s1, const char *s2);
char	*get_next_line(int fd);

#endif
