#include "../includes/push_swap.h"

void    verify_format(t_pswap *a_pswap, size_t nb_args, char **args)
{
    printf("verify_format nb_args = %lu\n", nb_args);//
    size_t  i;
    size_t  j;
    int len_nbr;

    i = 0;
    while (i < nb_args)
    {
        len_nbr = 0;
        j= 0;
        while(args[i][j] && ft_isspace(args[i][j])) // necess args[i][j] ?
            j++;
        if (args[i][j] && ft_issign(args[i][j]))// necess args[i][j] ?
            j++;
        while (args[i][j])
        {
            if(!ft_isdigit(args[i][j]))
                close_error(a_pswap, "argument : bad syntax");
            if(len_nbr > 10)
                close_error(a_pswap, "argument : at least 1 arg is too big for an int");
            len_nbr++;
            j++;
            // printf("i = %lu j = %lu\n", i, j);//

        }
        i++;
    }
}

void    extract_args(t_pswap *a_pswap, int nb_args, char **args)
{
    printf("extract_args\n");//
    size_t i;

    i = 0;
    // Si le programme est lancé avec un seul argument, on split ce dernier
    if (nb_args == 1)
        a_pswap->c2_args = ft_split(args[0], ' ');
    // Sinon on copie argv dans une chaine allouee
    else 
        a_pswap->c2_args = char2dup(args);
    if (!a_pswap->c2_args)
        close_error(a_pswap, "allocation : malloc error during arguments extraction in char2");
}

// int     *create_int1args(char **args) {
//     long nb;
//     int *int1args;
//     size_t nb_args;
//     size_t i;

//     i = 0;
//     nb_args = char2len(args);
//     int1args = (int *) ft_calloc(nb_args, sizeof(int));
//     if (!int1args)
//         return (NULL);
//     while (i < nb_args)
//     {
//         nb = ft_atol(args[i]);
        // if (nb > INT_MAX || nb < INT_MIN)
//             close_error("arguments : contains number too big for an int"); //creer des codes d' erreurs specifiques et des actions associees, j' ai le droit a exit
//         int1args[i] = (int) nb;
//         i++;
//     }
//     return (int1args);
// }

// char    **create_char2args(int size, char **args) {
//     char **char2args;
//     size_t i;

//     i = 0;
//     char2args = NULL;
//     // Si le programme est lancé avec un seul argument, on split ce dernier
//     if (size == 1)
//         char2args = ft_split(args[0], ' ');
//     // Sinon on copie argv dans une chaine allouee
//     else 
//         char2args = char2dup(args);
//     return (char2args);
// }

