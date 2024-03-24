/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:24:52 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/24 21:09:49 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (line == NULL)
	// 		break ;
	// 	count++;
	// 	printf("[%d]:%s\n", count, line);
	// 	free(line);
	// 	line = NULL;
	// }
	close(fd);
	return (0);
}
