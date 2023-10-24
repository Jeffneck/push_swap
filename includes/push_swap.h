#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h> //size_t
# include <unistd.h> //write
# include <stdlib.h> //malloc, free
# include <stdio.h> // printf (prohibited)
// structure des nodes de la stack 
// prev permet de remonter la stack en sens inverse mais n'est peut etre pas nécessaire.
typedef struct s_stelem
{
    int data;
    int final_pos; 
    struct s_stelem *prev;
    struct s_stelem *next;
}   t_stelem;

//structure qui conserve les données d'une stack
//si on veut modifier top, bottom ou size on envoie un pointeur vers cette structure dans la fonction.
typedef struct s_stconfig
{
    t_stelem *top; 
    t_stelem *bottom;
    size_t  size;
}   t_stconfig;

//structure qui me donne des infos sur mes portions, 
//utile pour définir la range actuelle de ma portion
//peut être pas nécessaire
typedef struct s_chuncks
{
    int nb_chuncks; //nb de portions choisies pas obligatoire ?
    int min_stA; //nb minimum détecté dans la stack
    int max_stA; //nb maximum détecté dans la stack
    int range;//diff entre min et max
}   t_chuncks;

//CREATE_STACK.c
t_stconfig  *ft_create_stack(int *p_data, size_t nb_args);
t_stconfig *ft_init_stack_config(void);

//PROCESS_ARGS.c
int *ft_args_to_int_tab(int size, char **args);

//STACK_OPERATIONS.c
int    operation_manager(t_stconfig *stA, t_stconfig *stB, char **operations);

//STACK_UTILS.c
int pos_min_stack(t_stconfig st);
int pos_max_stack(t_stconfig st);
int min_in_stack(t_stconfig st);
int max_in_stack(t_stconfig st);

//PUSH_SWAP.c
void    algo_3_stack(t_stconfig *stA, t_stconfig *stB);
void    algo_5_stack(t_stconfig *stA, t_stconfig *stB);
void    sort_stack(t_stconfig *stA, t_stconfig *stB);

//ALGO_BIG_STACK.c
t_chuncks *determine_chuncks(t_stconfig *stA);
int is_in_chunck(t_chuncks *chuncks, int curr_chunck, int nb);
int nearest_chunck_nb(t_chuncks *chuncks, int curr_chunck, t_stconfig *stA);
void presort_and_push_chuncks(t_chuncks *chuncks, t_stconfig *stA, t_stconfig *stB);
void insertion_sort_stB_to_stA(t_stconfig *stA, t_stconfig *stB);
void algo_big_stack(t_stconfig *stA, t_stconfig *stB);





#endif //PUSH_SWAP_H