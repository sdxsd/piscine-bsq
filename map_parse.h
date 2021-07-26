#include <stddef.h>

struct x_y
{
	int x;
	int y;
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
