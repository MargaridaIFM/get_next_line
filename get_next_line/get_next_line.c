/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:05:34 by mfrancis          #+#    #+#             */
/*   Updated: 2024/05/14 16:29:45 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
First define the fd,
Open a file with the open function with the only read option;
if fd is negative that means that the file cannot be open; 
the same thing if the buffer size is < 0;

Then we check if the firts character of the buffer is /0,
meaning the buffer is empty. In this case we read the data of fd to the buffer 
and we end with a null terminater (0);

While the buffer exists we will call the strjoin function
to concatenate the previouse line with the content of the buffer
end with a null terminater (0);
ig the buffer enconounter a \n but didint finish it will "print" until the /n 
and move anithing tha didin print to the beguinig of the 'new' buffer;
the if some error occur during the reading the memory will be free 
and return NULL
*/ 
char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[0])
		read(fd, buffer, BUFFER_SIZE);
	line = NULL;
	while (buffer[0])
	{
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
			return (NULL);
		if (organize_buffer(buffer) == 1)
			break ;
		if (read(fd, buffer, 0) < 0)
		{
			free(line);
			return (NULL);
		}
		read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}
/* int	main(void)
{
	FILE *file;
	char *line;

	// Open the file or use stdin for testing
	file = fopen("test1.txt", "r");
	if (!file)
	{
		perror("Error opening file");
		return (1);
	}
	// Read lines using your Get Next Line function
	while ((line = get_next_line(fileno(file))) != NULL)
	{
		printf("%s\n", line); // Print the line
		free(line);           // Free the memory allocated by get_next_line
	}
	printf("BUFFER SIZE: %i\n", BUFFER_SIZE);
	// Close the file
	fclose(file);
	return (0);
} */
int main()
{
	char *str = get_next_line(1000000);
	printf("%s\n", str);
	free(str);
}
