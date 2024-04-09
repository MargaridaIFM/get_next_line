# get_next_line
<div align = "center">

<img src = "https://www.vangproperties.com/media/3830/42lisboa.jpg?preset=imageWithTextInsideText" alt = "42 lisbon img">

</div>

## About

This project is about programming a function that returns a line read from a file descriptor. If the function is inserted into a loop, it allows the content of a file to be returned, line by line, until the end of the file.

## Mandatory

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/27eb8b37-c0f2-43fa-89c8-602f89e9c3dd/16bb3275-0ed8-4b1d-a98a-ebcd1268ce1f/Untitled.png)

- [x]  get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
- [x]  Your function should return the line that was read. If  its empy or error return NULL
- [x]  Functions works when its reading a file or standard input
- [x]  Returned line should include the terminating \n character, except if it's the end of the file and the line does not end with  \n.
- [x]  The  get_next_line.h header file should include at least the get_next_line() function.
- [x]  All adicional functions should be included in get_next_line_utils.c file
- [x]  To define the buffer size for  read(), add the option to the compiled file -D BUFFER_SIZE=n (ex p despois compilar: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c)
- [x]  IMPORTANTE/FORBIDDEN:
    - [x]  Libft
    - [x]  lseek()
    - [x]  Global variables

## Bonus

- [x]  Use only one static variable.
- [x]  Manage multiple file descriptors at the same time.
- [x]  Bonus files should include a suffix `_bonus.[c/h]:`
    - [x]  get_next_line_bonus.c
    - [x]  get_next_line_bonus.h
    - [x]  get_next_line_utils_bonus.c

