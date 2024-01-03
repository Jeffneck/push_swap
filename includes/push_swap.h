#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h> //size_t
# include <unistd.h> //write
# include <stdlib.h> //malloc, free
# include <limits.h> //INT_MAX, INT_MIN
# include <stdio.h> // printf (prohibited)
# include "../libft/libft.h"
// structure des nodes de la stack 
// prev permet de remonter la stack en sens inverse mais n'est peut etre pas nécessaire.
typedef struct s_stelem
{
    int data;
    struct s_stelem *prev;
    struct s_stelem *next;
}   t_stelem;

//structure qui conserve les données d'une stack
//si on veut modifier top, bottom ou size on envoie un pointeur vers cette structure dans la fonction.
typedef struct s_stconfig
{
    t_stelem *top; 
    t_stelem *bot;
    size_t  size;
}   t_stconfig;

typedef struct s_pswap
{
    char    **c2_args;
    size_t  nb_args;
    t_stconfig *sta;
    t_stconfig *stb;
} t_pswap; 

//structure qui me donne des infos sur mes portions, 
//utile pour définir la range actuelle de ma portion
//peut être pas nécessaire
// typedef struct s_chuncks
// {
//     int nb_chuncks; //nb de portions choisies pas obligatoire ?
//     int min_stA; //nb minimum détecté dans la stack
//     int max_stA; //nb maximum détecté dans la stack
//     int range;//diff entre min et max
// }   t_chuncks;

//CREATE_STACK.c
t_stconfig  *ft_create_stack(char **p2_args, size_t nb_args);
t_stconfig *ft_init_stack_config(void);

//PROCESS_ARGS.c
void    verify_format(t_pswap *a_pswap, size_t nb_args, char **args);
void    extract_args(t_pswap *a_pswap, int nb_args, char **args);

//MISC.C
void    free_stack(t_stconfig *st);
void	free_char2(char ***a_char2);
size_t	char2len(char **char2);
char **char2dup(char **char2);
int ft_issign(char c);

//MANAGE_ERRORS.C
int exit_error(char *strerr);
void    close_error(t_pswap *a_pswap, char *strerr);

//MANAGE_STELEMS.C
t_stelem *create_stelem(int data);
void    stack_push_front(t_pswap *a_pswap, t_stconfig *st, int data);
void    ft_display_stack(t_stconfig *st);

//SORTING_ALGO.C
void    sort_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb);

//STACK_OPERATIONS.c
void    operations_manager(t_pswap *a_pswap, t_stconfig *stA, t_stconfig *stB, char *str_ops);

//STACK_UTILS.c
int pos_min_stack(t_stconfig st);
int pos_max_stack(t_stconfig st);
int min_in_stack(t_stconfig st);
int max_in_stack(t_stconfig st);

// //PUSH_SWAP.c
// void    algo_3_stack(t_stconfig *stA, t_stconfig *stB);
// void    algo_5_stack(t_stconfig *stA, t_stconfig *stB);
// void    sort_stack(t_stconfig *stA, t_stconfig *stB);
// //ALGO_BIG_STACK.c
// t_chuncks *determine_chuncks(t_stconfig *stA);
// int is_in_chunck(t_chuncks *chuncks, int curr_chunck, int nb);
// int nearest_chunck_nb(t_chuncks *chuncks, int curr_chunck, t_stconfig *stA);
// void presort_and_push_chuncks(t_chuncks *chuncks, t_stconfig *stA, t_stconfig *stB);
// void insertion_sort_stB_to_stA(t_stconfig *stA, t_stconfig *stB);
// void algo_big_stack(t_stconfig *stA, t_stconfig *stB);






#endif //PUSH_SWAP_H