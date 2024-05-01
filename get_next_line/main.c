#include "get_next_line.h"

/*
First define the fd,
Open a file with the open function with the only read option;
if fd is negative that means that the file cannot be open.
if

Call the function get_next_line and storage it in the variable new_line;
if the new_line is NULL the loop break,
if it not it will print the number of line and the content of the	string;
close the file with close											function;
*/
int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("test.txt", O_RDONLY);
    next_line = get_next_line(fd);
	printf("str: %s", next_line);
/* 	 while (next_line)
	{
		printf("str: %s", next_line);
        next_line = get_next_line(fd);
	}
    close(fd); */
	return (0);
}