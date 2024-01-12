#include "../includes/push_swap.h"

void    swap_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
    // printf("swap_manager str = %s\n", operation);
    // ft_display_stack(stA); // test
    
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
    // printf("operation_exists\n");
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
    // printf("operations_manager\n");
    size_t  i;
    char    **operations;

    i = 0;
    // ft_printf("BEFORE STACK A *******************************\n");//
    // ft_display_stack(sta); // test
    // ft_printf("BEFORE STACK B *******************************\n");//
    // ft_display_stack(stb); // test

    operations = ft_split(str_ops, ','); //malloc teste
    a_pswap->curr_operations = operations;
    if (!operations)
        close_program(a_pswap, "Error\n");
    while(operations[i])
    {
        if (!operation_exists(operations[i])) // que pour le checker ou laisser quand meme ?
            close_program(a_pswap, "Error\n");
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
    // ft_printf("AFTER STACK A *******************************\n");//
    // ft_display_stack(sta); // test
    // ft_printf("AFTER STACK B *******************************\n");//
    // ft_display_stack(stb); // test
    // ft_printf("\n\n\n\n");//
}    
