/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:16:54 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/26 22:18:26 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	find_next_line_break(char *str, size_t i)
{
	char	*ptr;

	ptr = str + i;
	while (*ptr && *ptr != '\n')
		ptr++;
	if (*ptr == '\n')
		ptr++;
	return (ptr - str);
}

static char	*get_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stash || *stash == '\0')
		return (NULL);
	i = find_next_line_break(stash, i);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*(stash + i) && *(stash + i) != '\n')
	{
		*(line + i) = *(stash + i);
		i++;
	}
	if (*(stash + i) == '\n')
	{
		*(line + i) = *(stash + i);
		i++;
	}
	*(line + i) = '\0';
	return (line);
}

static char	*get_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!stash[0])
		return (free(stash), NULL);
	i = find_next_line_break(stash, i);
	new_stash = (char *)malloc((ft_strlen(stash) - i) + 1);
	if (!new_stash)
		return (free(new_stash), NULL);
	while (*(stash + i))
		*(new_stash + j++) = *(stash + i++);
	*(new_stash + j) = '\0';
	if (!*new_stash)
		return (free(stash), free(new_stash), NULL);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer_readed;
	int			bytes_readed;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_readed = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer_readed == NULL)
		return (NULL);
	bytes_readed = 1;
	while (!ft_strchr(stash, '\n') && bytes_readed != 0)
	{
		bytes_readed = read(fd, buffer_readed, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			stash = (free(buffer_readed), free(stash), NULL);
			return (NULL);
		}
		buffer_readed[bytes_readed] = '\0';
		stash = ft_strjoin(stash, buffer_readed);
	}
	free(buffer_readed);
	line = get_line(stash);
	stash = get_stash(stash);
	return (line);
}
