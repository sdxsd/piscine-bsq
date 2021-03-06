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
	while (map[index] != '\n')
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
	return (dimensions);
}

struct map_format get_parse_header(char *map)
{
	struct map_format	format; 
	format.empties = map[2];
	format.obstacles = map[3];
	format.squares = map[4];
	return (format);
}

char		*str_convert(char *map)
{
	int 				nl_count;
	struct x_y 			map_dims;
	struct map_format	format; 
	int 				iter_0;
	int 				iter_1;
	int					iter_2; 
	char 				*ptr; 
	char 				buf[262144];

	nl_count = 0;
	iter_0 = 0;
	iter_1 = 0;
	iter_2 = 0;
	ptr = &buf[0];
	map_dims = dimensions_func(map);
	format = get_parse_header(map);
	while (map[iter_1] <= map_dims.x)
	{	
		buf[iter_1] = '0';
		++iter_1;
	}
	buf[iter_1] = '\n';
	while (map[iter_1] != '\0')
	{
		if (map[iter_1] == format.empties)
			buf[iter_0] = '1';
		else if (map[iter_1] == format.obstacles)
			buf[iter_0] = '0';
		else if (map[iter_1] == '\n') 
		{
			buf[iter_0] = '\n';
		}
		else
			continue ;
		++iter_0;
		++iter_1;
	}
	buf[iter_0] = '\0';
	ft_putstr(buf);
	return (ptr);
}

char	*convert_2(char *map)
{
    struct x_y  map_dims;
    int         iter_0;
    int         iter_1;
	int 		iter_3;
    char        *map_1;
    char        buf[262144];
	char		top_left;
	char		top;
	char		left;
	char		lowest;
	//map_1 = str_convert(map);
    iter_0 = 0;
    iter_1 = 0;
    map_1 = &buf[0];
    map_dims = dimensions_func(map);

	while(map[iter_1] != '\n')
	{
		iter_1++;
	}
	iter_3 = iter_1;
	while (map[iter_3] != '\0')
	{
		buf[iter_3] = map[iter_3];
		++iter_3;
	}
    while (map[iter_1] != '\0')
    {
		if (map[iter_1] == '\n')
		{
			iter_1 = iter_1 + 2;
		}
        else
		{
			top_left = buf[iter_1 - map_dims.x - 2];
			top = buf[iter_1 - map_dims.x - 1];
			left = buf[iter_1 - 1];
			lowest = top_left;
			if (top < lowest)
				lowest = top;
			if (left < lowest)
				lowest = left;
			buf[iter_1] = lowest + 1;
        	++iter_1;
		}
    }
	char *pointer; 
	pointer = &buf[0];
    ft_putstr(pointer);
    return (pointer);
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
