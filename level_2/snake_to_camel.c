/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./camel_to_snake "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./camel_to_snake "hello_world" | cat -e
helloWorld$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	x;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			x = 0;
			if (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				write(1, &argv[1][i], 1);
			}
			else if (argv[1][i] == '_')
			{
				x = argv[1][i + 1] - 32;
				write (1, &x, 1);
				i++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
