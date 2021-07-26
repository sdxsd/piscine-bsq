#include <unistd.h>
// Remove this before final push.
#include <stdio.h>
// Remove this before final push.
#include <unistd.h>
#include <fcntl.h>

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

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

int	ft_str_is_numeric(char *str)
{
	int	iterator;

	iterator = 0;
	while (str[iterator] != '\0')
	{
		if (str[iterator] < '0' || str[iterator] > '9')
			return (0);
		++iterator;
	}
	if (iterator == 0)
		return (1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	iterator;

	iterator = 0;
	while (str[iterator] != '\0')
	{
		iterator++;
	}
	write(1, str, iterator);
}

int	ft_strlen(char *str)
{
	int	iterator;

	iterator = 0;
	while (str[iterator] != '\0')
		++iterator;
	return (iterator);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
