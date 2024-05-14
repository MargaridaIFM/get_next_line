#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char		buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	if(!buffer[fd][0])
		buffer[fd][read(fd, buffer[fd], BUFFER_SIZE)] = 0;
	line = NULL;
	while(buffer[fd][0])
	{
		line = ft_strjoin_GNL(line, buffer[fd]);
		if(!line)
				return(NULL);
		if(organize_buffer(buffer[fd]) == 1)
			break;
		if(read(fd, buffer[fd], 0) < 0)
		{
			free(line);
			return(NULL);
		}
		buffer[fd][read(fd, buffer[fd], BUFFER_SIZE)] = 0;
	}
	return(line);
}