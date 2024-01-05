#include "../includes/push_swap.h"

void     init_stacks(t_pswap *a_pswap)
{
    printf("init_stack_a\n");//
    a_pswap->sta = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));
    if(!a_pswap->sta)
        close_error(a_pswap, "Memory : error alloc init_stack A\n");
    a_pswap->stb = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));
    if(!a_pswap->stb)
        close_error(a_pswap, "Memory : error alloc init_stack B\n");
}

void    fill_stack_a(t_pswap *a_pswap)
{
    printf("fill_stack_a\n");
    t_stconfig *sta;
    char        **args;
    ssize_t     i_arg;
    long        nb;

    sta = a_pswap->sta;
    args = a_pswap->c2_args;
    i_arg = (ssize_t) a_pswap->nb_args - 1;
    nb = 0;
    while(i_arg >= 0)
    {
        nb = ft_atol(args[i_arg]);
        printf(" NB = %ld\n", nb);
        if (nb > (long)INT_MAX || nb < (long)INT_MIN)
            close_error(a_pswap, "Arguments : at leats 1 arg is too big for an int\n");
        stack_push_front(a_pswap, a_pswap->sta, (int) nb);
        i_arg--;
    }
}

int    main(int argc, char **argv)
{
    //ajouter une erreur si stack trop grande > ssize_t (notre prog pourra pas gerer )
    t_pswap pswap;
    char **char2args;
    ft_bzero(&pswap, sizeof(t_pswap)); // utile?
    init_stacks(&pswap);
    if (argc < 2)
        exit_error("Arguments : need at least 1 argument\n");
    extract_args(&pswap, argc - 1, &argv[1]);
    pswap.nb_args = char2len(pswap.c2_args);
    verify_format(&pswap, pswap.nb_args, pswap.c2_args);
    fill_stack_a(&pswap);
    printf("BEFORE\n"); 
    ft_display_stack(pswap.sta);
    sort_stack(&pswap, pswap.sta, pswap.stb);
    printf("AFTER\n"); 
    ft_display_stack(pswap.sta);
    return (0);
}

