#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"

// commandes sa, sb et ss
void    swap_top_stack(t_stconfig *st)
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
void    push_st1_to_st2(t_stconfig *st1, t_stconfig *st2)
{
    t_stelem *original_top_st2; 
    t_stelem *original_top_st1;

    original_top_st2 = st2->top;
    original_top_st1 = st1->top;

    if (!st1 || !st2)
        return; //erreur car une stack n'existe pas ?
    if (!st1->top)
        return; //erreur car push impossible ?
    
    //push du top node src sur st2
    st2->top = original_top_st1; 
    (st2->top)->next = original_top_st2;
    (st2->top)->prev = NULL;
    st2->size++;

    //pop du top node sur st1
    st1->top = original_top_st1->next;
    if (st1->top)
        (st1->top)->prev = NULL;
    st1->size--;
}

void    rotate_st(t_stconfig *st)
{
    t_stelem *original_top; 
    t_stelem *original_bot;

    original_top = st->top; 
    original_bot = st->bottom;

    if (!st)
        return; //erreur car une stack n'existe pas ?
    if (!st->top || st->top == st->bottom)
        return; // inutile de rotate si stack vide ou 1 seul elem.
    
    //pop top node
    st->top = original_top->next;
    (st->top)->prev = NULL;

    //push back top node
    st->bottom = original_top; 
    (st->bottom)->next = NULL;
    (st->bottom)->prev = original_bot;
}

void    reverse_rotate_st(t_stconfig *st)
{
    t_stelem *original_top; 
    t_stelem *original_bot; 
    t_stelem *original_prev_bot;

    original_top = st->top; 
    original_bot = st->bottom;
    original_prev_bot = (st->bottom)->prev; 

    if (!st)
        return; //erreur car une stack n'existe pas ?
    if (!st->top || st->top == st->bottom)
        return; // inutile de rotate si stack vide ou 1 seul elem.
    
    //make new top node
    st->top = original_bot;
    (st->top)->next = original_top;
    (st->top)->prev = NULL;

    //make new bottom node
    st->bottom = original_prev_bot; 
    (st->bottom)->next = NULL;
}

void    swap_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
    if (ft_strcmp(operation, "sa"))
        swap_top_stack(stA);
    else if (ft_strcmp(operation, "sb"))
        swap_top_stack(stB);
    else if (ft_strcmp(operation, "ss"))
    {
        swap_top_stack(stA);
        swap_top_stack(stB);
    }
}
void    push_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
    if (ft_strcmp(operation, "pa") == 0)
        push_st1_to_st2(stB, stA);
    else if (ft_strcmp(operation, "pb") == 0)
        push_st1_to_st2(stA, stB);
}
void    rotate_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
    if (ft_strcmp(operation, "ra") == 0)
        rotate_st(stA);
    else if (ft_strcmp(operation, "rb") == 0)
        rotate_st(stB);
    else if (ft_strcmp(operation, "rr") == 0)
    {
        rotate_st(stA);
        rotate_st(stB);
    }
}
void    reverse_rotate_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
    if (ft_strcmp(operation, "rra") == 0)
        reverse_rotate_st(stA);
    else if (ft_strcmp(operation, "rrb") == 0)
        reverse_rotate_st(stB);
    else if (ft_strcmp(operation, "rrr") == 0)
    {
        reverse_rotate_st(stA);
        reverse_rotate_st(stB);
    }
}



int     operation_exists (char *operation)
{
    char *valid_operations[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
    size_t num_valid_operations;
    size_t i; 

    i = 0;
    num_valid_operations = sizeof(valid_operations) / sizeof(valid_operations[0]);
    
    while (i < num_valid_operations) 
    {
        if (ft_strcmp(operation, valid_operations[i]) == 0) 
        {
            return 1; // Opération valide trouvée
        }
        i++;
    }
    return 0; // Aucune opération valide trouvée
}
int    operation_manager(t_stconfig *stA, t_stconfig *stB, char **operations)
{
    size_t i;

    i = 0;
    while(operations[i])
    {
        if (!operation_exists(operations[i]))
            return (0);
        else if (operations[i][0] == 's')
            swap_manager(stA, stB, operations[i]);
        else if (operations[i][0] == 'p')
            push_manager(stA, stB, operations[i]);
        else if (operations[i][0] == 'r' && ft_strlen(operations[i]) == 2)
            rotate_manager(stA, stB, operations[i]);
        else
            reverse_rotate_manager(stA, stB, operations[i]);
        printf("%s\n", operations[i]); //affichage de l'operation
    }
    return (1);
}    