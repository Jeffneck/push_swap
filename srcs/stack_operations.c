#include "../includes/push_swap.h"

/*operations on stack using operation manager that works with 
two separated t_stconfig 

the operation is treated in 2 times 
(operation manager uses the first letter to choose the 2nd func that uses strcmp to launch the good func)
*/


// commandes sa, sb et ss
void    swap_top_stack(t_stconfig *st) //faire des retours d' erreurs pour close en cas d'operation inadequate (utile  pour checker ?)
{
    printf("swap_top_stack\n");
    t_stelem tmp;
    t_stelem *el1; 
    t_stelem *el2; 

    // ft_display_stack(st); // test
    el1 = st->top;
    el2 = el1->next; //segfault ici
    ft_memcpy(&tmp, el2, sizeof(t_stelem));
    //erreurs pour le checker
    if (st->top == NULL || st->top == st->bot)
        return;
    el2->next = el1;
    el2->prev = NULL;
    el1->next = tmp.next;
    el1->prev = el2;

    st->top = el2;
    if(st->info.size == 2)
        st->bot = el1;
}

void    update_stinfo(t_stconfig *st1, t_stconfig *st2)
{
    st1->info.size--;
    st1->info.median = (st1->info.size) / 2;
    st2->info.size++;
    st2->info.median = (st2->info.size) / 2;
}

void    push_st1_to_st2(t_stconfig *st1, t_stconfig *st2)
{
    printf("push_st1_to_st2\n");
    t_stelem *top_s1; 
    t_stelem *top_s2; 
    t_stelem *next_s1; 

    top_s1 = st1->top;
    next_s1 = top_s1->next;
    top_s2 = st2->top;
    //erreurs pour le checker
    if (!top_s1)
        return; //erreur car push impossible ?
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
    printf("rotate_st\n");
    t_stelem *top; 
    t_stelem *bot;
    t_stelem *prev_bot;

    top = st->top; 
    bot = st->bot;
    prev_bot = bot->prev;
    //erreurs pour le checker :
    if (!st)
        return; //erreur car une stack n'existe pas ?
    if (st->info.size < 2)
        return; // inutile de rotate si stack vide ou 1 seul elem.
    bot->prev = NULL;
    bot->next = top;
    top->prev = bot;
    prev_bot->next = NULL;
    st->top = bot;
    st->bot = prev_bot;
}

void    rotate_st(t_stconfig *st)
{
    printf("rotate_st\n");
    t_stelem *top; 
    t_stelem *top_next;
    t_stelem *bot;

    top = st->top; 
    top_next = top->next;
    bot = st->bot;
    
    //erreurs pour le checker :
    if (!st)
        return; //erreur car une stack n'existe pas ?
    if (st->info.size < 2)
        return; // inutile de rotate si stack vide ou 1 seul elem.
    top_next->prev = NULL;
    bot->next = top;
    top->next = NULL;
    top->prev = bot;
    st->top = top_next;
    st->bot = top;
}

void    swap_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
    printf("swap_manager str = %s\n", operation);
    ft_display_stack(stA); // test
    
    if (ft_strcmp(operation, "sa") == 0)
        swap_top_stack(stA);
    else if (ft_strcmp(operation, "sb") == 0)
        swap_top_stack(stB);
    else if (ft_strcmp(operation, "ss") == 0)
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

//pour le checker ?
int     operation_exists (char *operation)
{
    printf("operation_exists\n");
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

void    operations_manager(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb, char *str_ops)
{
    printf("operations_manager\n");
    size_t  i;
    char    **operations;

    i = 0;
    ft_printf("BEFORE STACK A *******************************\n");//
    ft_display_stack(sta); // test
    ft_printf("BEFORE STACK B *******************************\n");//
    ft_display_stack(stb); // test

    operations = ft_split(str_ops, ',');
    a_pswap->curr_operations = operations;
    if (!operations)
        close_error(a_pswap, "allocation : malloc error during split\n");
    while(operations[i])
    {
        // sleep(3);//
        if (!operation_exists(operations[i])) // que pour le checker ou laisser quand meme ?
            close_error(a_pswap, "sorting : at least one operation used does not exist\n");
        if (operations[i][0] == 's')
            swap_manager(sta, stb, operations[i]);
        else if (operations[i][0] == 'p')
            push_manager(sta, stb, operations[i]);
        else if (operations[i][0] == 'r' && ft_strlen(operations[i]) == 2)
            rotate_manager(sta, stb, operations[i]);
        else
            reverse_rotate_manager(sta, stb, operations[i]);
        ft_printf("%s\n", operations[i]); //affichage de l'operation
        i++;
    }
    free_char2(&(a_pswap->curr_operations));
    a_pswap->curr_operations = NULL;
    ft_printf("AFTER STACK A *******************************\n");//
    ft_display_stack(sta); // test
    ft_printf("AFTER STACK B *******************************\n");//
    ft_display_stack(stb); // test
}    
