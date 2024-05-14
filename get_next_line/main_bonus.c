#include "get_next_line_bonus.h"
int main()
{
	int fd[3];

	fd[0] = open("test1.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	char *test1 = get_next_line(fd[0]);
	char *test2 = get_next_line(fd[1]);
	char *test3 = get_next_line(fd[2]);
	while(test1 || test2 || test3)
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
}