/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:12:22 by mfidimal          #+#    #+#             */
/*   Updated: 2024/04/05 12:55:27 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_ft_read	ft_read(int fd)
{
	char	*buf;
	t_ft_read	read_value;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
	{
		free(buf);
		read_value.buf = NULL;
		read_value.bytes_readed = -1;
		return (read_value);
	}
	read_value.bytes_readed = read(fd, buf, BUFFER_SIZE);
	if (read_value.bytes_readed == -1)
	{
		free(buf);
		read_value.buf = NULL;
		read_value.bytes_readed = -1;
		return (read_value);
	}
	buf[read_value.bytes_readed] = '\0';
	read_value.buf = buf;
	return (read_value);
}

char	*get_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		if (j == i)
			line[j] = '\n';
		else
			line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_stash_and_free(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		if (stash[i] == '\0')
			return (NULL);
		i++;
	}
	new_stash = (char *)malloc(sizeof(char) * ft_strlen(&stash[i + 1]) + 1);
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
	t_ft_read	read_value;
	char		*line;

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
