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

void    fill_stack_a(t_pswap *a_pswap, t_stconfig *sta, char **c2_args, int nb_args)
{
    printf("fill_stack_a\n");
    long        nb;
    int         i;

    nb = 0;
    i = nb_args - 1;
    while(i >= 0)
    {
        nb = ft_atol(c2_args[i]);
        // printf(" NB = %ld\n", nb);//
        if (nb > (long)INT_MAX || nb < (long)INT_MIN)
            close_error(a_pswap, "arguments : at leats 1 arg is too big for an int\n");
        stack_push_front(a_pswap, a_pswap->sta, (int)nb);
        i--;
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
        close_error(&pswap, "Arguments : need at least 1 argument\n");
    extract_args(&pswap, argc, argv);
    verify_args_format(&pswap, pswap.nb_args, pswap.c2_args);
    fill_stack_a(&pswap, pswap.sta, pswap.c2_args, pswap.nb_args);
    sort_stack(&pswap, pswap.sta, pswap.stb);
    close_error(&pswap, NULL);
    return (0);// inutile puisque exit_success
}

