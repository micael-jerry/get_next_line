/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:12:22 by mfidimal          #+#    #+#             */
/*   Updated: 2024/04/04 11:27:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ft_read_t	ft_read(int fd)
{
	ft_read_t read_value;

	read_value.buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_value.buf)
	{
		read_value.buf = NULL;
		read_value.bytes_readed = -1;
		return (read_value);
	}
	read_value.bytes_readed = read(fd, read_value.buf, BUFFER_SIZE);
	if (read_value.bytes_readed == -1)
	{
		read_value.buf = NULL;
		read_value.bytes_readed = -1;
		return (read_value);
	}
	read_value.buf[read_value.bytes_readed] = '\0';
	return read_value;
}

char	*get_line(char *stash)
{
	char *line;
	int i;
	int j;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = (char *) malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_stash_and_free(char *stash)
{
	char *new_stash;
	int i;
	int j;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		if (stash[i] == '\0')
			return (NULL);
		i++;
	}
	new_stash = (char *) malloc(sizeof(char) * ft_strlen(&stash[i + 1]) + 1);
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
	{
		new_stash[j] = stash[i];
		j++;
		i++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	ft_read_t	read_value;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_value.bytes_readed = 1;
	while (!ft_strchr(stash, '\n') && read_value.bytes_readed != 0)
	{
		read_value = ft_read(fd);
		if (read_value.bytes_readed == -1)
		{
			free(read_value.buf);
			free(stash);
            stash = NULL;
            return (NULL);
		}
		stash = strjoin_free(stash, read_value.buf);
	}
	free(read_value.buf);
	line = get_line(stash);
	stash = get_stash_and_free(stash);
	return (line);
}
