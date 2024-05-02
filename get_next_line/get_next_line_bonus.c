#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	if(!buffer[0])
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	line = NULL;
	while(buffer[0])
	{
		line = ft_strjoin_GNL(line, buffer);
		if(!line)
				return(NULL);
		if(organize_buffer(buffer) == 1)
			break;
		if(read(fd, buffer, 0) < 0)
		{
			free(line);
			return(NULL);
		}
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	}
	return(line);
}