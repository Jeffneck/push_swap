#include "../includes/push_swap.h"

// Remplir la liste A avec les données initiales
t_stelem *create_stelem(int data)
{
    printf("ft_create_elem \n");
    t_stelem *new_elem;

    new_elem = (t_stelem*) malloc(sizeof(t_stelem));
    if (!new_elem)
        return (NULL);
    new_elem->data = data;
    new_elem->prev = NULL;
    new_elem->next = NULL;
    return (new_elem);
}

void    stack_push_front(t_pswap *a_pswap, t_stconfig *st, int data)
{
    printf("fstack_push_front \n");
    t_stelem *new_elem;

    new_elem = create_stelem(data);
    if (new_elem == NULL)
        close_error(a_pswap, "allocation : malloc error during stelem creation\n");
    if (!st->top)
        st->bot = new_elem;
    else 
    {
        new_elem->next = st->top;
        (st->top)->prev = new_elem;
    }
    st->top = new_elem;
    st->size++;
}


void    ft_display_stack(t_stconfig *st)
{
    printf("ft_display_stack \n");
    t_stelem *current; 
    size_t  i; 

    i = 0;
    current = st->top; 
    while(current)
    {
        printf("%u: %u\n", i, current->data);
        current = current->next;
        i++;
    }
    printf("size in stconfig = %u, real size = %u \n", st->size, i);
}


// int main ()
// {
//     //test pour voir si la stack se remplit correctement
//     int tab10[] = {2, 4, 1, 5, 3, 8, 6, 7, 0, 9};
//     size_t size_tab10 = 10;
//     t_stconfig *st_test10 = ft_create_stack(tab10, size_tab10);
//     ft_display_stack(st_test10);
    
//     int *tab0= NULL;
//     size_t size_tab0 = 0;
//     t_stconfig *st_test0 = ft_create_stack(tab0, size_tab0);
//     ft_display_stack(st_test0);
    
//     int tab1[] = {2};
//     size_t size_tab1 = 1;
//     t_stconfig *st_test1 = ft_create_stack(tab1, size_tab1);
//     ft_display_stack(st_test1);
//     return(0);
// }

