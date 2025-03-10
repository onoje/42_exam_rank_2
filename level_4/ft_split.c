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

char    **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    char **tab;
    tab = malloc(10000000);
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i])
    {
        tab[j] = malloc(10000000);
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            tab[j][k++] = str[i++];
        tab[i][k] = '\0';
        k = 0;
        j++;
        while (str[i] == ' ' || str[i] == '\t')
            i++;
    }
    tab[j] = NULL;
    return(tab);
}
