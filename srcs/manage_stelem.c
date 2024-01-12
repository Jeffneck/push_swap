#include "../includes/push_swap.h"

t_stelem *create_stelem(int data)
{
    t_stelem *new_elem;

    new_elem = (t_stelem*) malloc(sizeof(t_stelem));
    if (!new_elem)
        return (NULL);
    new_elem->data = data;
    new_elem->pos = 0; 
    new_elem->target_pos = 0;
    new_elem->prev = NULL;
    new_elem->next = NULL;
    return (new_elem);
}

void    stack_push_front(t_pswap *a_pswap, t_stconfig *st, int data)
{
    t_stelem *new_elem;

    new_elem = create_stelem(data);
    if (new_elem == NULL)
        close_program(a_pswap, "Error\n");
    if (!st->top)
        st->bot = new_elem;
    else 
    {
        new_elem->next = st->top;
        st->top->prev = new_elem;
    }
    st->top = new_elem;
    st->info.size++;
}


// void    ft_display_stack(t_stconfig *st)
// {
//     t_stelem *curr; 
//     int  i; 

//     i = 0;
//     curr = st->top; 
//     while(curr)
//     {
//         ft_printf("%d: data=%d pos=%d target_pos=%d\n", i, curr->data, curr->pos, curr->target_pos);
//         curr = curr->next;
//         i++;
//     }
// }

