#include "../includes/push_swap.h"

void    algo_3_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
    //trouver la position de max et min puis faire les op correspondantes
    printf("algo_3_stack\n");
    
    size_t pos_min; 
    size_t pos_max;

    pos_min = pos_min_stack(*sta);
    pos_max = pos_max_stack(*sta);
    if (pos_min == 0)
    {
        if (pos_max == 2)
            return; 
        else
            operations_manager(a_pswap, sta, stb, "sa,ra");
    }
    else if (pos_max == 0)
    {
        if (pos_min == 1)
            operations_manager(a_pswap, sta, stb, "ra");
        else
            operations_manager(a_pswap, sta, stb, "sa,rra");
    }
    else 
    {
        if (pos_min == 1)
            operations_manager(a_pswap, sta, stb, "sa");
        else
            operations_manager(a_pswap, sta, stb, "rra");
    }
    
}

void	algo_big_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
    if(sta->size > 4)
	    operations_manager(a_pswap, sta, stb, "pb");
    operations_manager(a_pswap, sta, stb, "pb");
    
    
    
    //CHAQUE TOUR :
    //calculer la cible de chaque node (closest smaller || max)
    //calculer le nombre de coups necessaire pou que ch node atteigne ca cible

    
    
}

void    sort_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
    if (sta->size <= 3)
        algo_3_stack(a_pswap, sta, stb);
    else
        algo_big_stack(a_pswap, sta, stb);
}