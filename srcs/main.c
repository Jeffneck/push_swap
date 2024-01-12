#include "../includes/push_swap.h"

int    main(int argc, char **argv)
{
    t_pswap pswap;
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

