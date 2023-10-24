#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"

// Remplir la liste A avec les données initiales
t_stelem *ft_create_elem(int data)
{
    printf("ft_create_elem \n");
    t_stelem *new_elem;

    new_elem = (t_stelem*) malloc(sizeof(t_stelem));
    if (!new_elem)
        return (NULL);
    new_elem->data = data;
    new_elem->final_pos = -1; 
    new_elem->prev = NULL;
    new_elem->next = NULL;
    return (new_elem);
}

int    ft_stack_push_front(t_stconfig *st, int data)
{
    printf("ft_stack_push_front \n");
    t_stelem *new_elem;

    new_elem = ft_create_elem(data);
    if (new_elem == NULL)
        return (0);
    if (!st->top)
    {
        st->bottom = new_elem;
    }
    else 
    {
        new_elem->next = st->top;
        (st->top)->prev = new_elem;
    }
    st->top = new_elem;
    st->size++;
    return (1);
}

t_stconfig *ft_init_stack_config(void)
{
    printf("ft_init_stack_config \n");
    t_stconfig *st;

    st = (t_stconfig *) malloc (sizeof(t_stconfig));
    if (st == NULL)
        return (NULL);
    st->top = NULL;
    st->bottom = NULL;
    st->size = 0;
    return (st);
}

t_stconfig  *ft_create_stack(int *p_data, size_t nb_args)
{ 
    printf("ft_create_stack \n");
    t_stconfig *st;
    ssize_t i; // necessaire d'utiliser ssize_t ?

    i = nb_args - 1;
    st = ft_init_stack_config();
    if (st == NULL)
        return(NULL);
    while (i >= 0)
    {
        ft_stack_push_front(st, p_data[i]);
        i--;
    }
    return (st);
}

// func that defines the final pos of each elem of the stack when it'll be sorted
// helps to facilitate the algos work + checker work
void    add_final_indexation_to_stelems(t_stconfig st)
{
    t_stelem *current;
    t_stelem *compared;
    int final_index;
    
    current = st.top;
    final_index = 0;
    if (st.size < 2)
        return (NULL);
    while(current)
    {
        compared = st.top;
        while(compared)
        {
            if (compared->data < current->data)
                final_index++;
            compared = compared->next;
        }
        current->final_pos = final_index;
        current = current->next;
    }
}

/*
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


int main ()
{
    //test pour voir si la stack se remplit correctement
    int tab10[] = {2, 4, 1, 5, 3, 8, 6, 7, 0, 9};
    size_t size_tab10 = 10;
    t_stconfig *st_test10 = ft_create_stack(tab10, size_tab10);
    ft_display_stack(st_test10);
    
    int *tab0= NULL;
    size_t size_tab0 = 0;
    t_stconfig *st_test0 = ft_create_stack(tab0, size_tab0);
    ft_display_stack(st_test0);
    
    int tab1[] = {2};
    size_t size_tab1 = 1;
    t_stconfig *st_test1 = ft_create_stack(tab1, size_tab1);
    ft_display_stack(st_test1);
    return(0);
}
*/
