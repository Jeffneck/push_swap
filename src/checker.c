#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"

int a_is_sorted(t_stconfig stA)
{
    printf("CHECKER.c : a_is_sorted \n");
    t_stelem *current; 

    current = stA.top; 
    while(current)
    {
        if (current->prev && (current->prev)->data > current->data);
            return (0);
        current = current->next;
    }
    return (1);
}

int b_is_empty(t_stconfig stB)
{
    printf("CHECKER.c : b_is_empty \n");
    if (stB.top)
        return (0);
    return (1);
}

void checker(t_stconfig *stA, t_stconfig *stB)
{
    //lire stdin avec get next line ?
    
}

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
int    main(int argc, char *argv[]) 
{
    t_stconfig *stA;
    t_stconfig *stB;
    int *tab;
    size_t size_tab;

    if (argc < 2)
        return;
    tab = ft_args_to_int_tab(argc - 1, &argv[1]);
    stA = ft_create_stack(tab, (size_t)(argc - 1));
    stB = ft_create_stack(NULL, 0);
}

int 

