int *dimensions(char *map)
{
   int index;
   int i;
   int j;

   index = 0;
   i = 0;
   j = 0;

   while(map[index] != '\n')
	  i++;

   index = 0;

   while(map[index] != '\0')
   {
	  if(map[index] == '\n')
		 j++;
   }
   dimensions[1] = i;
   dimensions[2] = j;
   return(dimensions)
}

char **map_parse(char *map, int dimensions)
{
   int i;
   int j;
   int count_i;
   int count_j;
   int index;

   i = dimensions[1];
   j = dimensions[2];
   count_i = 0;
   count_j = 0;
   index = 0;

   while(count_j < j)
   {
	  while(count_i < i)
	  {
		 map_parse[i][j] = map[index];
		 index++;
		 i++;
	  }
	  j++;
	  i = 0;
   }
   return(map_parse);

}
