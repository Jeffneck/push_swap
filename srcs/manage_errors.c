#include "../includes/push_swap.h"

int exit_error(char *strerr)
{
    ft_putstr_fd(strerr, 2);
    exit(EXIT_FAILURE);
}

void    close_error(t_pswap *a_pswap, char *strerr) // les elements ne peuvent pas etre mis a NULL dans les fonctions directement?
{
    printf("ft_close_error\n");
    // ft_printf("1\n");
    if (a_pswap->c2_args)
        free_char2(&(a_pswap->c2_args));
    // ft_printf("1\n");
    if (a_pswap->curr_operations)
        free_char2(&(a_pswap->curr_operations));
    if (a_pswap->sta)
        free_stack(a_pswap->sta);
    // ft_printf("1\n");
    if (a_pswap->stb)
        free_stack(a_pswap->stb);
    // ft_printf("1\n");
    if (strerr)
        exit_error(strerr);
    exit(EXIT_SUCCESS);
}