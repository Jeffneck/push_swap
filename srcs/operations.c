#include "../includes/push_swap.h"

void    swap_top_stack(t_stconfig *st)
{
    t_stelem tmp;
    t_stelem *first; 
    t_stelem *second; 
    t_stelem *third; 

    first = st->top;
    second = first->next;
    third = second->next;
    ft_memcpy(&tmp, second, sizeof(t_stelem));
    if (st->top == NULL || st->top == st->bot)
        return;
    second->next = first;
    second->prev = NULL;
    first->next = tmp.next;
    first->prev = second;

    st->top = second;
    if(st->info.size == 2)
        st->bot = first;
    if (st->info.size > 2)
        third->prev = first;
}

void    push_st1_to_st2(t_stconfig *st1, t_stconfig *st2)
{
    t_stelem *top_s1; 
    t_stelem *top_s2; 
    t_stelem *next_s1; 

    top_s1 = st1->top;
    next_s1 = top_s1->next;
    top_s2 = st2->top;
    if (!top_s1)
        return;
    st2->top = top_s1;
    top_s1->next = top_s2;
    if (!top_s2)
        st2->bot = top_s1;
    else
        top_s2->prev = top_s1;

    st1->top = next_s1;
    if (next_s1)
        next_s1->prev = NULL;
    update_stinfo(st1, st2);
}


void    reverse_rotate_st(t_stconfig *st)
{
    t_stelem *top; 
    t_stelem *bot;
    t_stelem *prev_bot;

    top = st->top; 
    bot = st->bot;
    prev_bot = st->bot->prev;
    if (!st)
        return;
    if (st->info.size < 2)
        return;
    bot->prev = NULL;
    bot->next = top;
    top->prev = bot;
    prev_bot->next = NULL;
    st->top = bot;
    st->bot = prev_bot;
}

void    rotate_st(t_stconfig *st)
{
    t_stelem *top; 
    t_stelem *top_next;
    t_stelem *bot;

    top = st->top; 
    top_next = top->next;
    bot = st->bot;
    
    if (!st)
        return;
    if (st->info.size < 2)
        return;
    top_next->prev = NULL;
    bot->next = top;
    top->next = NULL;
    top->prev = bot;
    st->top = top_next;
    st->bot = top;
}
