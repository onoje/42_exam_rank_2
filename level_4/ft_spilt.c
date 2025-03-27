/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

char	**ft_split(char *str)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	char	**temp;

	temp = malloc(1000000);
	while (str[i])
	{
		temp[j] = malloc(1000000);
		while (str[i] == 32 || str[i] == 9 || str[i] == 10)
			i++;
		if (!str[i])
			break ;
		k = 0;
		while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 10)
			temp[j][k++] = str[i++];
		temp[j][k] = '\0';
		j++;
	}
	temp[j] = NULL;
	return (temp);
}
