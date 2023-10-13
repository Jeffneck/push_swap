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

typedef struct s_chuncks
{
    int nb_chuncks; //pas obligatoire ?
    int min_stA;
    int max_stA; //pas obligatoire ? 
    int range;
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

#endif //PUSH_SWAP_H