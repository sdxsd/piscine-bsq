#include <unistd.h>
// Remove this before final push.
#include <stdio.h>
// Remove this before final push.
#include <unistd.h>
#include <fcntl.h>

#ifndef LIB_H
# define LIB_H

char	*ft_strcpy(char *dest, const char *src);
int		ft_str_is_numeric(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
char *map_to_string(char *file);

#endif /* LIB_H */
