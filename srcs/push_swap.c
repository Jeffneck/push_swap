#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"
/*
Ensemble des fonctions qui calculent les opérations optimales à effectuer sur les stacks 
pour trier les entiers le plus rapidement possible dans la stack A
*/
void    algo_3_stack(t_stconfig *stA, t_stconfig *stB)
{
    //trouver la position de max et min puis faire les op correspondantes
    size_t pos_min; 
    size_t pos_max;

    pos_min = pos_min_stack(*stA);
    pos_max = pos_max_stack(*stA);
    if (pos_min == 0)
    {
        if (pos_max == 2)
            return; 
        else
            operation_manager(stA, stB, ft_strsplit("sa,ra", ','));
    }
    else if (pos_max == 0)
    {
        if (pos_min == 1)
            operation_manager(stA, stB, ft_strsplit("ra", ','));
        else
            operation_manager(stA, stB, ft_strsplit("sa,rra", ','));
    }
    else 
    {
        if (pos_min == 1)
            operation_manager(stA, stB, ft_strsplit("sa", ','));
        else
            operation_manager(stA, stB, ft_strsplit("rra", ','));
    }
    
}

void    algo_5_stack(t_stconfig *stA, t_stconfig *stB)
{
    operation_manager(stA, stB, ft_strsplit("pb,pb", ','));
    algo_3_stack(stA, stB);
    if (stB->top < stA->top)
        operation_manager(stA, stB, ft_strsplit("pa", ','));
    else if (stB->top > stA->top)
        operation_manager(stA, stB, ft_strsplit("pa,ra", ','));
    else if (stB->top > stA->top->next)
        operation_manager(stA, stB, ft_strsplit("ra,pa,rra", ','));
    else
        operation_manager(stA, stB, ft_strsplit("rra,pa,ra,ra", ','));
}

void    sort_stack(t_stconfig *stA, t_stconfig *stB)
{
    if (stA->size < 3)
        algo_3_stack(stA, stB);
    else if (stA->size < 5)
        algo_5_stack(stA, stB);
    else
        algo_big_stack(stA, stB);
    
}