#include "../includes/push_swap.h"

int pos_min_stack(t_stconfig st)
{
    t_stelem *current;
    int pos_min;
    int min;
    int i; //size_t ?
    if (st.top == NULL)
        return (-1);
    pos_min = 0;
    i = 0;
    current = st.top;
    min = current->data;
    while (current)
    {
        if (current->data < min)
        {
            min = current->data;
            pos_min = i;
        }
        current = current->next;
        i++; 
    }
    // ft_printf("pos min in stack is : %d\n", pos_min);
    return (pos_min);
}
int pos_max_stack(t_stconfig st)
{
    t_stelem *current;
    int pos_max;
    int max;
    int i; //size_t ?
    
    if (st.top == NULL)
        return (-1);
    pos_max = 0;
    i = 0;
    current = st.top;
    max = current->data;
    while (current)
    {
        if (current->data > max)
        {
            max = current->data;
            pos_max = i;
        }
        current = current->next;
        i++; 
    }
    return (pos_max);
}

int min_in_stack(t_stconfig st)
{
    t_stelem *current;
    int min;
    if (st.top == NULL)
        return (0);
    current = st.top;
    min = current->data;
    while (current)
    {
        if (current->data < min)
            min = current->data;
        current = current->next;
    }
    return (min);
}
int max_in_stack(t_stconfig st)
{
    t_stelem *current;
    int max;
    if (st.top == NULL)
        return (0);
    current = st.top;
    max = current->data;
    while (current)
    {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return (max);
}