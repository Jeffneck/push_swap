#include "../includes/push_swap.h"

int exit_error(char *strerr)
{
    ft_putstr_fd(strerr, 2);
    exit(EXIT_FAILURE);
}

void    close_error(t_pswap *a_pswap, char *strerr)
{
    if (a_pswap->c2_args)
        free_char2(a_pswap->c2_args);
    if (a_pswap->sta)
        free_stconfig(a_pswap->sta);
    if (a_pswap->stb)
        free_stconfig(a_pswap->stb);
    exit_error(strerr);
}