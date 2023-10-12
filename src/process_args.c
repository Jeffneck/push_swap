#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"

int *ft_args_to_int_tab(int size, char **args)
{
    char **c_tab;
    int *i_tab;
    int i; 

    c_tab = NULL;
    i_tab = NULL;
    
    if (size == 1)
        c_tab = ft_strsplit(args[0], ' ');
    else
        c_tab = args;
    if (c_tab == NULL)
        return (NULL);
    //transformer un tableau de str en tab d'int
    i = 0;
    while (i < size)
    {
        i_tab[i] = ft_atoi(c_tab[i]);
        i++;
    }
}