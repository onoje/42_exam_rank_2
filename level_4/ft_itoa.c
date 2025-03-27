/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		len = 0;
	int		tmp;
	char	*str;

	tmp = nbr;
	if (tmp <= 0)
		len = 1;
	while (tmp)
	{
		tmp = tmp / 10;
		len ++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		str[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
