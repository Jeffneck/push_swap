#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h> //size_t
# include <unistd.h> //write
# include <stdlib.h> //malloc, free

typedef struct s_stelem
{
    int data;
    struct s_stack *prev;
    struct s_stack *next;
}   t_stelem;

typedef struct s_stconfig
{
    t_stelem *top; 
    t_stelem *bottom;
    size_t  size;
}   t_stconfig;

#endif //PUSH_SWAP_H