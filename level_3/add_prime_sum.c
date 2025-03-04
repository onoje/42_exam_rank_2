/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 9 || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_is_prime(int number)
{
	int	i;

	i = 2;
	if (number <= 1)
		return (0);
	while (number > i)
	{
		if (number % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int sum)
{
	char	c;

	if (sum > 9)
	{
		ft_putnbr(sum / 10);
		ft_putnbr(sum % 10);
	}
	else
	{
		c = sum + 48;
		write (1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	int	number;
	int	sum;

	sum = 0;
	if (argc != 2 || argv[1][0] == '-')
	{
		write(1, "0\n", 2);
		return (0);
	}
	number = ft_atoi(argv[1]);
	while (number > 1)
	{
		if (ft_is_prime(number))
			sum = sum + number;
		number--;
	}
	ft_putnbr(sum);
	write (1, "\n", 1);
}
