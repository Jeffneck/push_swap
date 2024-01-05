#include "../includes/push_swap.h"

void    algo_3_stack(t_pswap *a_pswap, t_stconfig *sta)
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

size_t  closest_smaller_pos(int obj, t_stconfig st_target)
{
    t_stelem    *curr;
    size_t      target_pos;
    size_t      i;
    int      target;
    int         found;

    curr = st_target.top;
    target = INT_MIN;
    target_pos = 0;
    i = 0;
    found = 0;
    while(curr)
    {
        if (curr->data > target && obj > curr->data) //verif
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

size_t  closest_bigger_pos(int obj, t_stconfig st_target)
{
    t_stelem    *curr;
    size_t      target_pos;
    size_t      i;
    int      target;
    int         found;

    curr = st_target.top;
    target = INT_MIN;
    target_pos = 0;
    i = 0;
    found = 0;
    while(curr)
    {
        if (curr->data < target && obj < curr->data) //verif
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
    size_t      pos;

    pos = 0;
    while(!el)
    {
        el->pos = pos;
        if(mode = 0)
            el->target_pos = closest_smaller_pos(el->data, st2);
        else
            el->target_pos = closest_bigger_pos(el->data, st2);
        pos++;
        el = el->next;
    }
}

t_mvset    find_elem_cheapest_moveset(t_stelem el, t_stinfo info_st1, t_stinfo info_st2)
{
    size_t  nb_moves;

    if (el.pos < info_st1.median && el.target_pos < info_st2.median)
    {
        nb_moves = max_value(el.pos, el.target_pos, sizeof(size_t));
        return ((t_mvset) {nb_moves, el.pos, el.target_pos});
    }
    else if (el.pos > info_st1.median && el.target_pos > info_st2.median)
    {
        nb_moves = max_value((info_st1.size - el.pos), (info_st2.size - el.target_pos), sizeof(size_t));
        return ((t_mvset) {nb_moves, (el.pos - info_st1.size), (el.target_pos - info_st2.size)});
    }
    else if (el.pos < info_st1.median && el.target_pos > info_st2.median)
    {
        nb_moves = el.pos + (info_st2.size - el.target_pos);
        return ((t_mvset) {nb_moves, el.pos, (info_st2.size - el.target_pos)});
    }
    else
    {
        nb_moves= (info_st1.size - el.pos) + el.target_pos;
        return((t_mvset) {nb_moves, (info_st1.size- el.pos), el.target_pos});
    }
}

t_mvset    find_cheapest_moveset(t_pswap *a_pswap, t_stconfig *st1, t_stconfig *st2, bool mode)
{
    t_stelem *el;
    t_mvset global_cheapest;
    t_mvset tmp;
    
    el = st1->top;
    while(el)
    {
        tmp = find_elem_cheapest_moveset(*el, st1->info, st2->info);
        if (tmp.nb_moves < global_cheapest.nb_moves)
            global_cheapest.nb_moves = tmp.nb_moves;
        el = el->next;
    }
    //on fait en sorte que st1 => stA et st2 => stB
    if (mode = 1)
    {
        tmp = global_cheapest;
        global_cheapest.mv_a = tmp.mv_b;
        global_cheapest.mv_b = tmp.mv_a;
    }
    return(global_cheapest);
}

int     determine_sign(ssize_t nombre)
{
    if (nombre > 0)
        return 1;
    else if (nombre < 0)
        return -1;
    else 
        return 0;
}

void    apply_double_moves(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb, t_mvset mvset)
{
    while (mvset.mv_a > 0 && mvset.mv_b > 0)
    {
        operations_manager(a_pswap, sta, stb, "rr");
        mvset.mv_a--; 
        mvset.mv_b--;
    }
    while (mvset.mv_a < 0 && mvset.mv_b < 0)
    {
        operations_manager(a_pswap, sta, stb, "rr");
        mvset.mv_a++; 
        mvset.mv_b++;
    }
}

void    apply_moves(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb, t_mvset mvset)
{
    int     step_st1;
    int     step_st2;

    step_st1 = determine_sign(mvset.mv_a);
    step_st2 = determine_sign(mvset.mv_b);
    
    //mv indivs
    apply_double_moves(a_pswap, sta, stb, mvset);
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
        if (mvset.mv_b > 0)
            operations_manager(a_pswap, sta, stb, "rb");
        else
            operations_manager(a_pswap, sta, stb, "rrb");
        mvset.mv_b += step_st2; 
    }
}

void	algo_big_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
    
    t_mvset cheapest;
    operations_manager(a_pswap, sta, stb, "pb");
    if(sta->info.size > 4)
	    operations_manager(a_pswap, sta, stb, "pb");
    while(sta->info.size > 3)
    {
        update_pos_and_target(sta->top, *stb, 0);
        cheapest = find_cheapest_moveset(a_pswap, sta, stb, 0);
        apply_moves(a_pswap, sta, stb, cheapest);
    }
    algo_3_stack(a_pswap, sta);
    while(stb->info.size > 0)
    {
        update_pos_and_target(stb->top, *sta, 1);
        cheapest = find_cheapest_moveset(a_pswap, stb, sta, 1);
        apply_moves(a_pswap, sta, stb, cheapest);
    }    
}

void    sort_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
    if (sta->info.size <= 3)
        algo_3_stack(a_pswap, sta);
    else
        algo_big_stack(a_pswap, sta, stb);
}








// void	find_moves_to_target(t_stconfig st1, t_stconfig st2, bool mode)
// {
//     t_stelem    *curr1;
//     size_t      target_pos;
//     size_t      pos;

//     curr1 = st1.top;
//     pos = 0;
//     while(!curr1)
//     {
//         if(mode = 0)
//             target_pos = closest_smaller_pos(curr1->data, st2);
//         else
//             target_pos = closest_bigger_pos(curr1->data, st2);
//         curr1->moves.c_up = pos;
//         curr1->moves.c_down = st1.size - pos;
//         curr1->moves.t_up = target_pos;
//         curr1->moves.t_down = st2.size - target_pos;
//         pos++;
//         curr1 = curr1->next;
//     }
// }


// t_mvset define_cheapest_moves_for_el(t_stelem *curr)
// {    
//     t_mvset cheapest;
//     t_
//     size_t  tmp_nb_moves;

//     tmp_nb_moves = max_value(curr.moves.c_up, curr.moves.t_up, sizeof(size_t));
//     cheapest = (t_mvset) {tmp_nb_moves, UP, curr.moves.c_up, UP, curr.moves.t_up};
//     tmp_nb_moves = max_value(curr.moves.c_down, curr.moves.t_down, sizeof(size_t));
//     if(tmp_nb_moves < cheapest.nb_moves)
//         cheapest = (t_mvset) {tmp_nb_moves, DOWN, curr.moves.c_down, DOWN, curr.moves.t_down};
//     tmp_nb_moves = curr.moves.c_up + curr.moves.t_down;
//     if(tmp_nb_moves < cheapest.nb_moves)
//         cheapest = (t_mvset) {tmp_nb_moves, UP, curr.moves.c_up, DOWN, curr.moves.t_down};
//     tmp_nb_moves = curr.moves.c_down + curr.moves.t_up;
//     if(tmp_nb_moves < cheapest.nb_moves)
//         cheapest = (t_mvset) {tmp_nb_moves, DOWN, curr.moves.c_down, UP, curr.moves.t_up};
//     return (cheapest);
// }

// t_mvset define_cheapest_moves_for_el(t_stelem curr)
// {    
//     t_mvset cheapest;
//     size_t  moves_meter;
//     size_t  tmp;
//     moves_meter = max_value(curr.moves.c_up, curr.moves.t_up, sizeof(size_t));
//     cheapest = (t_mvset) {UP, curr.moves.c_up, UP, curr.moves.t_up};
//     tmp = max_value(curr.moves.c_down, curr.moves.t_down, sizeof(size_t));
//     if(tmp < moves_meter)
//     {
//         moves_meter = tmp;
//         cheapest = (t_mvset) {DOWN, curr.moves.c_down, DOWN, curr.moves.t_down};
//     }
//     tmp = curr.moves.c_up + curr.moves.t_down;
//     if(tmp < moves_meter)
//     {
//         moves_meter = tmp;
//         cheapest = (t_mvset) {UP, curr.moves.c_up, DOWN, curr.moves.t_down};
//     }
//     tmp = curr.moves.c_down + curr.moves.t_up;
//     if(tmp < moves_meter)
//         cheapest = (t_mvset) {DOWN, curr.moves.c_down, UP, curr.moves.t_up};
//     return (cheapest);
// }
