#include "../includes/push_swap.h"

void     init_stacks(t_pswap *a_pswap)
{
    a_pswap->sta = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));
    if(!a_pswap->sta)
        close_program(a_pswap, "Memory : error alloc init_stack A\n");
    a_pswap->stb = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));
    if(!a_pswap->stb)
        close_program(a_pswap, "Memory : error alloc init_stack B\n");
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
