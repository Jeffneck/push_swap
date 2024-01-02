#include "../includes/push_swap.h"

void     init_stacks(t_pswap *a_pswap)
{
    a_pswap->sta = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));
    if(!a_pswap->sta)
        close_error(a_pswap, "Erreur allocation stack A");
    a_pswap->stb = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));
    if(!a_pswap->stb)
        close_error(a_pswap, "Erreur allocation stack B");
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
        if (nb > INT_MAX || nb < INT_MIN)
            close_error(a_pswap, "arguments : at leats 1 arg is too big for an int");
        stack_push_front(a_pswap, a_pswap->sta, (int) nb);
        i_arg--;
    }
}

int    main(int argc, char **argv)
{
    t_pswap pswap;
    char **char2args;

    if (argc < 2)
        exit_error("arguments : need at least 1 argument");
    extract_args(&pswap, argc - 1, &argv[1]);
    pswap.nb_args = char2len(pswap.c2_args);
    verify_format(pswap.nb_args, pswap.c2_args);
    init_stacks(&pswap);
    fill_stack_a(&pswap);
    ft_display_stack(pswap.sta); //afficher la stack pour voir s' il n' y a pas de conneries
    //apply_sorting_algo(&pswap);
    return (0);
}

