#include "../includes/push_swap.h"

void     init_stacks(t_pswap *a_pswap)
{
    a_pswap->sta = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig)); //malloc testé
    if(!a_pswap->sta)
        close_program(a_pswap, "Memory : error alloc init_stack A\n");
    a_pswap->stb = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));//malloc testé
    if(!a_pswap->stb)
        close_program(a_pswap, "Memory : error alloc init_stack B\n");
}

int is_duplicata(int nb, t_stconfig *sta)
{
    t_stelem *curr;

    curr = sta->top;
    while (curr)
    {
        if (nb == curr->data)
            return (1);
        curr = curr->next;
    }
    return (0);
}

void    fill_stack_a(t_pswap *a_pswap, t_stconfig *sta, char **c2_args, int nb_args)
{
    long        nb;
    int         i;

    nb = 0;
    i = nb_args - 1;
    while(i >= 0)
    {
        nb = ft_atol(c2_args[i]);
        if(is_duplicata(nb, sta))
                close_program(a_pswap, "Error\n");
        if (nb > (long)INT_MAX || nb < (long)INT_MIN)
            close_program(a_pswap, "Error\n");
        stack_push_front(a_pswap, a_pswap->sta, (int)nb);
        i--;
    }
}

int     stack_is_sorted(t_stconfig *st)
{
    t_stelem *curr;
    t_stelem *next;

    if (st->info.size == 1)
        return (1);
    curr = st->top;
    next = curr->next;
    while (next)
    {
        if (curr->data > next->data)
            return (0);
        curr = curr->next;
        next = next->next;
    }
    return (1);
}

int    main(int argc, char **argv)
{
    t_pswap pswap;
    char **char2args;
    ft_bzero(&pswap, sizeof(t_pswap));
    init_stacks(&pswap);
    if (argc < 2)
        close_program(&pswap, NULL);
    extract_args(&pswap, argc, argv);
    verify_args_format(&pswap, pswap.nb_args, pswap.c2_args);
    fill_stack_a(&pswap, pswap.sta, pswap.c2_args, pswap.nb_args);
    if(stack_is_sorted(pswap.sta))
        close_program(&pswap, NULL);
    sort_stack(&pswap, pswap.sta, pswap.stb);
    close_program(&pswap, NULL);
    return (0);
}

