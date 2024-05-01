# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

//define when compille with the flags -D BUFFER_SIZE=n
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);

int	ft_strlen_GNL(char *s);
char *ft_strjoin_GNL(char *prefix, char *sufix);
char *clean_buffer(char *buffer);
int	ft_strlen(const char *s);

#endif