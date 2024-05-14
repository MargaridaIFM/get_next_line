/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:05:12 by mfrancis          #+#    #+#             */
/*   Updated: 2024/05/14 15:59:32 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer[fd][0])
		buffer[fd][read(fd, buffer[fd], BUFFER_SIZE)] = 0;
	line = NULL;
	while (buffer[fd][0])
	{
		line = ft_strjoin_gnl(line, buffer[fd]);
		if (!line)
			return (NULL);
		if (organize_buffer(buffer[fd]) == 1)
			break ;
		if (read(fd, buffer[fd], 0) < 0)
		{
			free(line);
			return (NULL);
		}
		buffer[fd][read(fd, buffer[fd], BUFFER_SIZE)] = 0;
	}
	return (line);
}
/* int	main(void)
{
	int fd[3];

	fd[0] = open("test1.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	char *test1 = get_next_line(fd[0]);
	char *test2 = get_next_line(fd[1]);
	char *test3 = get_next_line(fd[2]);
	while (test1 || test2 || test3)
	{
		printf("test1: %s\n", test1);
		printf("test2: %s\n", test2);
		printf("test3: %s\n", test3);
		test1 = get_next_line(fd[0]);
		test2 = get_next_line(fd[1]);
		test3 = get_next_line(fd[2]);
	}
	free(test1);
	free(test2);
	free(test3);

	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
} */