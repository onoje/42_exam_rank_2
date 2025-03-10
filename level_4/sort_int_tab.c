/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

#include <unistd.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	index;
	int		tmp;
	int		swapped;

	if (size <= 1)
		return ;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		index = 0;
		while (index < (size - 1))
		{
			if (tab[index] > tab[index + 1])
			{
				tmp = tab[index];
				tab[index] = tab[index + 1];
				tab[index + 1] = tmp;
				swapped = 1;
			}
			index++;
		}
	}
}
