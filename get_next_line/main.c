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
	FILE	*file;
	char	*line;

	// Open the file or use stdin for testing
	file = fopen("test.txt", "r");
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
}