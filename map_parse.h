#include <stddef.h>

struct x_y
{
	int x;
	int y;
};

struct map_format
{
	char empties; 
	char obstacles; 
	char squares; 
};

struct x_y dimensions_func(char *map)
{
	struct x_y dimensions;
	int index;
	int i;
	int j;

	index = 0;
	i = 0;
	j = 0;

	while(map[index] != '\n')
	{
		index++;
		i++;
	}

	index = 0;

	while(map[index] != '\0')
	{
		if(map[index] == '\n')
			j++;
		index++;
	}
	dimensions.x = i;
	dimensions.y = j;
	return(dimensions);
}

char		*str_convert(char *map)
{
	int 		nl_count;
	struct x_y 	map_dims;
	int 		iter_0;
	int 		iter_1;
	char 		*ptr; 
	char 		buf[262144];

	iter_0 = 0;
	iter_1 = 0;
	ptr = &buf[0];
	map_dims = dimensions_func(map);
	nl_count = 0;
	while (map[iter_1] != '\n')
		++iter_1;
	while (map[iter_1] != '\0')
	{
		if (map[iter_1] == '.')
			buf[iter_0] = 1;
		else if (map[iter_1] == 'o')
			buf[iter_0] = 0;
		else if (map[iter_1] == '\n')
			buf[iter_0] = '\n';
		else
			continue ;
		++iter_0;
		++iter_1;
	}
	buf[iter_0] = '\0';
	ft_putstr(buf);
	return (ptr);
}

char	*convert_2(char *ptr, char *map)
{
    int         nl_count;
    struct x_y  map_dims;
    int         iter_0;
    int         iter_1;
    char        *map_1;
    char        buf[262144];
	char		top_left;
	char		top;
	char		left;
	char			lowest;
	
	map_1 = str_convert(map);
    iter_0 = 0;
    iter_1 = 0;
    output = &buf[0];
    map_dims = dimensions_func(map);
    nl_count = 0;
	while(map[iter_1] != '\n')
	{
		buf[iter_0] = map[iter_1];
		iter_0 ++;
		iter_1 ++;
	}
    while (ptr[iter_1] != '\0')
    {
		if (map[iter_1] == '\n')
		{
			buf[iter_0] = map[iter_1];
			buf[iter_0 + 1] = map[iter_1 + 1]
			iter_1 = iter_1 + 2;
			iter_0 = iter_0 + 2;
        else
		{
			top_left = buf[iter_0 - map_dims.x - 2];
			top = buf[iter_0 - map_dims.x - 1];
			left = buf[iter_0 - 1];
			lowest = top_left;
			if (top < lowest)
				lowest = top;
			if (left < lowest)
				lowest = left;
			buf[iter] = lowest + 1;
        	++iter_0;
        	++iter_1;
		}
    }
    buf[iter_0] = '\0';
    ft_putstr(buf);
    return (output);

struct map_format get_parse_header(char *map)
{
	int iter;
	struct map_format; 

	iter = 0; 
	while (map[iter] != '\n')
	{

	}
}

char **map_parse(char *map, struct x_y dims)
{
	struct x_y dimens;
	int i;
	int j;
	int count_i;
	int count_j;
	int index;
	char **map_parse = NULL;
	// Doesn't do anything.
	if (dims.x){}
	// // Doesn't do anything.

	dimens = dimensions_func(map);
	i = dimens.x;
	j = dimens.y;
	count_i = 0;
	count_j = 0;
	index = 0;

	while(count_j < j)
	{
		while(count_i < i)
		{
			if(map[index] == '\n')
			{
				index++;
				i++;
			}
			if(map[index] != '\n')
			{
				map_parse[i][j] = map[index];
				index++;
				i++;
			}
		}
		j++;
		i = 0;
	}
	return(map_parse);
}
