#include "get_next_line.h"

/*
First define the fd,
Open a file with the open function with the only read option;
if fd is negative that means that the file cannot be open.
if 

Call the function get_next_line and storage it in the variable new_line; 
if the new_line is NULL the loop break,
if it not it will print the number of line and the content of the string;
close the file with close function;
*/
int main(void)
{
    int fd;
    char *next_line;
    int line_nr;

    line_nr = 0;
    fd = open("teste.txt", O_RDONLY);
    if (fd == -1)
	{
		perror("ERROR: Impossible to open the file\n");
		return (1);
	}
    while (1 /*ou usar fd?*/)
    {
        next_line = get_next_line(fd);
        if(next_line == NULL)
            break;
        line_nr++;
        printf("Line %d: %s\n", line_nr, next_line);
        free(next_line);
        next_line = NULL;
    }
    close(fd);
    return(0);
    
}