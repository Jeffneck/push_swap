#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"

int    main(int argc, char *argv[]) 
{
    t_stconfig *stA;
    t_stconfig *stB;
    int *tab;

    if (argc < 2)
        return (1);
    tab = ft_args_to_int_tab(argc - 1, &argv[1]);
    stA = ft_create_stack(tab, (size_t)(argc - 1));
    stB = ft_create_stack(NULL, 0);
    sort_stack(stA,stB);
    return (0);
}