#include "../includes/push_swap.h"

void    algo_3_stack(t_pswap *a_pswap, t_stconfig *sta)
{
    //trouver la position de max et min puis faire les op correspondantes
    // ft_printf("algo_3_stack\n");
    
    size_t pos_min; 
    size_t pos_max;

    pos_min = pos_min_stack(*sta);
    pos_max = pos_max_stack(*sta);
    if (pos_min == 0)
    {
        if (pos_max == 2)
            return; 
        else
            operations_manager(a_pswap, sta, a_pswap->stb, "sa,ra");
    }
    else if (pos_max == 0)
    {
        if (pos_min == 1)
            operations_manager(a_pswap, sta, a_pswap->stb, "ra");
        else
            operations_manager(a_pswap, sta, a_pswap->stb, "sa,rra");
    }
    else 
    {
        if (pos_min == 1)
            operations_manager(a_pswap, sta, a_pswap->stb, "sa");
        else
            operations_manager(a_pswap, sta, a_pswap->stb, "rra");
    }
    
}

int  closest_smaller_pos(int obj, t_stconfig st_target)
{
    // ft_printf("closest_smaller_pos\n");
    
    t_stelem    *curr;
    int      target_pos;
    int      i;
    long      target;
    int         found;

    curr = st_target.top;
    target = -2147483650;
    target_pos = 0;
    i = 0;
    found = 0;
    while(curr)
    {
        if ((long) curr->data > target && obj > curr->data) //ve
        {
            target = curr->data;
            target_pos = i;
            found = 1;
        }
        i++;
        curr = curr->next;
    }
    if (!found)
        target_pos = pos_max_stack(st_target);
    return (target_pos);
}

int  closest_bigger_pos(int obj, t_stconfig st_target)
{
    t_stelem    *curr;
    int      target_pos;
    int      i;
    long      target;
    int         found;

    curr = st_target.top;
    target = 2147483650;
    target_pos = 0;
    i = 0;
    found = 0;
    while(curr)
    {
        if ((long)curr->data < target && obj < curr->data) //erreur ici
        {
            target = curr->data;
            target_pos = i;
            found = 1;
        }
        i++;
        curr = curr->next;
    }
    if (!found)
        target_pos = pos_min_stack(st_target);
    return (target_pos);
}

void	update_pos_and_target(t_stelem *el, t_stconfig st2, bool mode)
{
    int      pos;

    pos = 0;
    while(el)
    {
        el->pos = pos;
        if(mode == 0)
            el->target_pos = closest_smaller_pos(el->data, st2);
        else
            el->target_pos = closest_bigger_pos(el->data, st2);
        pos++;
        el = el->next;
    }

}

int    return_max_int(int nb1, int nb2)
{
    if (nb1 >= nb2)
        return(nb1);
    return (nb2); 
}

int    return_min_int(int nb1, int nb2)
{
    if (nb1 <= nb2)
        return(nb1);
    return (nb2); 
}

int absolute(int num) 
{
    if (num < 0)
        return -num;
    return num;
}

t_mvset    find_elem_cheapest_moveset(t_stelem el, t_stinfo info_st1, t_stinfo info_st2)
{
    // ft_printf("find_elem_cheapest_moveset\n");
    int  nb_moves;
    int  el_moves;
    int  target_moves;

    el_moves = el.pos;
    if (el.pos > info_st1.median)
        el_moves = el.pos - info_st1.size;

    target_moves = el.target_pos;
    if (el.target_pos > info_st2.median)
        target_moves = el.target_pos - info_st2.size;

    nb_moves = absolute(el_moves) + absolute(target_moves);
    if ((el_moves > 0 && target_moves > 0))
        nb_moves = return_max_int(el_moves, target_moves);
    else if (el_moves < 0 && target_moves < 0)
        nb_moves = return_min_int(el_moves, target_moves);
    // ft_printf("Elem MOVESET : El.data=%d El.pos :%d el.target_pos=%d nb_moves : %d  MV A : %d MV B : %d\n", el.data, el.pos, el.target_pos, nb_moves, el_moves, target_moves);
    return ((t_mvset) {nb_moves, el_moves, target_moves});
}

t_mvset    find_cheapest_moveset(t_pswap *a_pswap, t_stconfig *st1, t_stconfig *st2, bool mode)
{
    t_stelem *el;
    t_mvset global_cheapest;
    t_mvset tmp;
    
    el = st1->top;
    global_cheapest = (t_mvset) {INT_MAX, INT_MAX, INT_MAX};
    while(el)
    {
        tmp = find_elem_cheapest_moveset(*el, st1->info, st2->info);
        if (absolute(tmp.nb_moves) < absolute(global_cheapest.nb_moves))
            global_cheapest = tmp;
        el = el->next;
    }
    if (mode == 1)
    {
        tmp = global_cheapest;
        global_cheapest.mv_a = tmp.mv_b;
        global_cheapest.mv_b = tmp.mv_a;
    }
    // ft_printf("CHEAPEST MOVESET : NB_MOVES=%d  MV_A=%d MV_B=%d\n", global_cheapest.nb_moves, global_cheapest.mv_a, global_cheapest.mv_b);
    return(global_cheapest);
}

int     determine_step(ssize_t nombre)
{
    if (nombre > 0)
        return -1;
    else if (nombre < 0)
        return 1;
    else 
        return 0;
}

void    apply_double_moves(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb, t_mvset *mvset)
{
    // ft_printf("apply_double_moves\n");
    while (mvset->mv_a > 0 && mvset->mv_b > 0)
    {
        operations_manager(a_pswap, sta, stb, "rr");
        mvset->mv_a--; 
        mvset->mv_b--;
    }
    while (mvset->mv_a < 0 && mvset->mv_b < 0)
    {
        operations_manager(a_pswap, sta, stb, "rrr");
        mvset->mv_a++; 
        mvset->mv_b++;
    }
}

void    apply_moves(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb, t_mvset mvset)
{
    // ft_printf("apply_moves\n");
    int     step_st1;
    int     step_st2;

    step_st1 = determine_step(mvset.mv_a);
    step_st2 = determine_step(mvset.mv_b);
    
    apply_double_moves(a_pswap, sta, stb, &mvset);
    //mv indivs
    while (mvset.mv_a != 0)
    {
        if (mvset.mv_a > 0)
            operations_manager(a_pswap, sta, stb, "ra");
        else
            operations_manager(a_pswap, sta, stb, "rra");
        mvset.mv_a += step_st1; 

    }
    while (mvset.mv_b != 0)
    {
        // printf("MOVES RESTANTS = %d", mvset.mv_b);
        if (mvset.mv_b > 0)
            operations_manager(a_pswap, sta, stb, "rb");
        else
            operations_manager(a_pswap, sta, stb, "rrb");
        mvset.mv_b += step_st2; 
    }
}

void	algo_big_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
    
    // ft_printf("algo_big_stack\n");
    t_mvset cheapest;
    t_mvset reset;
    ft_bzero(&reset, sizeof(t_mvset));
    // ft_printf("111111111111\n");//
    operations_manager(a_pswap, sta, stb, "pb");
    if(sta->info.size > 4)
	    operations_manager(a_pswap, sta, stb, "pb");
    while(sta->info.size > 3)
    {
        // ft_printf("///////////////STACK A => STACK B /////////////////\n");//
        update_pos_and_target(sta->top, *stb, 0);
        // ft_display_stack(sta);//
        cheapest = find_cheapest_moveset(a_pswap, sta, stb, 0);
        apply_moves(a_pswap, sta, stb, cheapest);
        operations_manager(a_pswap, sta, stb, "pb");
        // ft_printf("333333333333\n");//
    }
    // ft_printf("///////////////ALGO 3 /////////////////\n");//
    algo_3_stack(a_pswap, sta);
    while(stb->info.size > 0)
    {
        // ft_printf("///////////////STACK B => STACK A /////////////////\n");//
        update_pos_and_target(stb->top, *sta, 1);
        cheapest = find_cheapest_moveset(a_pswap, stb, sta, 1);
        apply_moves(a_pswap, sta, stb, cheapest);
        operations_manager(a_pswap, sta, stb, "pa");
    }
    reset.mv_a = pos_min_stack(*sta);
    if (reset.mv_a > sta->info.median)
        reset.mv_a = reset.mv_a - sta->info.size;
    // ft_printf("reset.mv_a = %d", reset.mv_a);
    apply_moves(a_pswap, sta, stb, reset);
}

void    sort_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
    // ft_printf("sort_stack\n");
    if (sta->info.size <= 3)
        algo_3_stack(a_pswap, sta);
    else
        algo_big_stack(a_pswap, sta, stb);
}

