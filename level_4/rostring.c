/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	ft_print_first_word(char *str, int begin_space)
{
	while (str[begin_space] != '\0' && !is_space(str[begin_space]))
	{
		ft_putchar(str[begin_space]);
		begin_space++;
	}
}

void	rostring(char *str)
{
	int idx = 0;
	int begin_space = 0;

	while (str[begin_space] != '\0' && is_space(str[begin_space]))
		begin_space++;
	
	while (str[idx] != '\0')
	{
		if (str[idx] != '\0' && !is_space(str[idx]) && is_space(str[idx - 1]))
		{
			while (str[idx] != '\0' && !is_space(str[idx]))
			{
				ft_putchar(str[idx]);
				idx++;
			}
			ft_putchar(' ');
		}
		idx++;
	}
	ft_print_first_word(str, begin_space);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	ft_putchar('\n');
	return (0);
}
