#include "push_swap.h"
// Remplir la liste A avec les données initiales
t_stelem *ft_create_elem(int data)
{
    t_stelem *new_elem;

    new_elem = (t_stelem*) malloc(sizeof(t_stelem));
    if (!new_elem)
        return (NULL);
    new_elem->data = data; 
    new_elem->prev = NULL;
    new_elem->next = NULL;
    return (new_elem);
}

int    ft_stack_push_front(t_stconfig *st, int data)
{
    t_stelem *new_elem;

    new_elem = ft_create_elem(data);
    if (new_elem == NULL)
        return (0);
    if (st->top == NULL) 
    {
        // Si la pile est vide, il suffit d'affecter new_elem à top_stack.
        st->top = new_elem;
    }
    else
    {
        new_elem->next = st->top;
        (st->top)->prev = new_elem; //prev inutile ? 
        st->top = new_elem;
    }
    return (1);
}
// le 1er argument est en 1re position
t_stconfig *ft_init_stack_config(void)
{
    t_stconfig *st;

    st = (t_stconfig *) malloc (sizeof(t_stconfig));
    if (st == NULL)
        return (NULL);
    st->top = NULL;
    st->bottom = NULL;
    st->size = 0;
    return (st);
}

t_stconfig  *ft_fill_stack(int *p_data, size_t nb_args)
{ 
    t_stconfig *st;
    size_t i;

    i = 0;
    st = ft_init_stack_config();
    if (st == NULL)
        return(NULL);
    while (i < nb_args)
    {
        ft_stack_push_front(st, p_data[isatty])
    }
}