// Remove this before final push.
#include <stdio.h>
// Remove this before final push.
#include <unistd.h>
#include <fcntl.h>
#include "lib.h"

char *map_to_string(char *file)
{
    char hold_char[32768];
    int fd;
    int iterator;
    char *ptr;

    ptr = &hold_char[0];
    iterator = 0;
    fd = open(file, O_RDONLY);
    while (hold_char[iterator] != '\0')
    {
        read(fd, &hold_char[iterator], 1);
        iterator++;
    }
    close(fd);
    return (ptr);
}

int main(int argc, char *argv[])
{
    char *file;
    char *first_line;

    if (argc != 2)
        write(1, "Error\n", 5);
    else {
        file = argv[1];
        first_line = map_to_string(file);
        ft_putstr(first_line);
    }
}
