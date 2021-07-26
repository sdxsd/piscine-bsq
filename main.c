#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *get_line(char *file)
{
    char hold_char[8096];
    int fd;
    int iterator;

    iterator = 0;
    fd = open(file, O_RDONLY);
    while (hold_char[iterator] != '\n')
    {
        read(fd, &hold_char[iterator], 1);
        iterator++;
    }
    hold_char[iterator] = '\0';
    close(fd);
    printf("%s\n", hold_char);
    return (0);
}

int main(int argc, char *argv[])
{
    char *file;
    char *first_line;

    if (argc != 2)
        write(1, "Error\n", 6);

    file = argv[1];
    first_line = get_line(file);
    //printf("%s", first_line);
}
