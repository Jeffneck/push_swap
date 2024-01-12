#include "../includes/push_swap.h"

int exit_error(char *strerr)
{
    ft_putstr_fd(strerr, 2);
    exit(EXIT_FAILURE);
}

void    close_program(t_pswap *a_pswap, char *strerr)
{
    if (a_pswap->c2_args)
        free_char2(&(a_pswap->c2_args));
    if (a_pswap->checker)
        free(a_pswap->checker);
    if (a_pswap->curr_operations)
        free_char2(&(a_pswap->curr_operations));
    if (a_pswap->sta)
        free_stack(a_pswap->sta);
    if (a_pswap->stb)
        free_stack(a_pswap->stb);
    if (strerr)
        exit_error(strerr);
    exit(EXIT_SUCCESS);
}