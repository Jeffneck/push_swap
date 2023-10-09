#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"

// commandes sa, sb et ss
void swap_top_stack(t_stconfig *st)
{
    t_stelem *original_first;
    t_stelem *original_second;

    if (st->top == NULL || st->top == st->bottom)
        return;
    original_first = st->top; 
    original_second = original_first->next;

    //2eme node remplace le 1er
    st->top = (st->top)->next;
    //on met à jour les pointeurs next et prev du nouveau first node
    (st->top)->next = original_first;
    (st->top)->prev = NULL;

    //on met à jour les pointeurs next et prev du nouveau second node
    ((st->top)->next)->next = original_second->next; 
    ((st->top)->next)->prev = original_second;
}

// the top element of st_src is popped from st_src and then puhed on the top of st_dest
void    push_st1_to_st2(t_stconfig *st_src, t_stconfig *st_dest)
{
    t_stelem *original_top_dest; 
    t_stelem *original_top_src;

    original_top_dest = st_dest->top;
    original_top_src = st_src->top;

    if (!st_src || !st_dest)
        return; //erreur car une stack n'existe pas ?
    if (!st_src->top)
        return; //erreur car push impossible ?
    
    //push du top node src sur st_dest
    st_dest->top = original_top_src; 
    (st_dest->top)->next = original_top_dest;
    (st_dest->top)->prev = NULL;
    st_dest->size++;

    //pop du top node sur st_src
    st_src->top = original_top_src->next;
    if (st_src->top)
        (st_src->top)->prev = NULL;
    st_src->size--;
}

void    