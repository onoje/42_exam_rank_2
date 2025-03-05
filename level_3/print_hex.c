/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int	ft_puthexanbr_lower(unsigned long nbr)
{
	char	x;

	if (nbr >= 16)
		ft_puthexanbr_lower(nbr / 16);
	if (nbr % 16 < 10)
	{
		x = '0' + (nbr % 16);
		write(1, &x, 1);
	}
	else
	{
		x = 'a' + (nbr % 16 - 10);
		write(1, &x, 1);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		ft_puthexanbr_lower(ft_atoi(argv[1]));
	}
	write (1, "\n", 1);
}
