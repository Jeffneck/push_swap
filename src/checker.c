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

