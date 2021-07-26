// Remove this before final push.
#include <stdio.h>
// Remove this before final push.
#include <unistd.h>
#include <fcntl.h>
#include "lib.h"
#include "map_parse.h"



int main(int argc, char *argv[])
{
    char *file;
    char *map;

    if (argc != 2)
        write(1, "Error\n", 5);
    else
    {
        file = argv[1];
        map = map_to_string(file);
        ft_putstr(map);

        dimensions(map);
    }
}
