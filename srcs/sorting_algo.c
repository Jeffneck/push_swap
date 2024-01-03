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

// int     find_closest_smaller(int obj, t_stconfig st_target)
// {
//     t_stelem    *curr;
//     int         target;
//     int         found;

//     curr = st_target.top;
//     target = INT_MIN;
//     found = 0;
//     while(curr)
//     {
//         if (curr->data > target && curr->data < obj)
//         {
//             target = curr->data;
//             found = 1;
//         }
//         curr = curr->next;
//     }
//     if (!found)
//         target = max_in_stack(st_target);
//     return (target);
// }

//pas sur que l'algo soit bon
// int     find_closest_bigger(int obj, t_stconfig st_target)
// {
//     t_stelem    *curr;
//     int         target;
//     int         found;

//     curr = st_target.top;
//     target = INT_MIN;
//     found = 0;
//     while(curr)
//     {
//         if (curr->data > target && curr->data > obj)
//         {
//             target = curr->data;
//             found = 1;
//         }
//         curr = curr->next;
//     }
//     if (!found)
//         target = min_in_stack(st_target);
//     return (target);
// }

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

t_mvset    find_cheapest_moveset(t_pswap *a_pswap, t_stconfig *st1, t_stconfig *st2)
{
    t_stelem *el;
    t_mvset cheapest;
    size_t  nb_moves;
    size_t    median_st1;
    size_t    median_st2;

    el = st1->top;
    median_st1 = st1->size / 2;
    median_st2 = st2->size / 2;
    while(el)
    {
        nb_moves = max_value(el->pos, el->target_pos, sizeof(size_t));
        cheapest = (t_mvset) {nb_moves, UP, el->pos, UP, el->target_pos};
        nb_moves = max_value((st1->size - el->pos), (st2->size - el->target_pos), sizeof(size_t)); //valider
        if (nb_moves < cheapest.nb_moves && el->pos > median_st1 && el->target_pos > median_st2)
            cheapest = (t_mvset) {nb_moves, DOWN, (st1->size - el->pos), DOWN, (st2->size - el->target_pos)};
        nb_moves = el->pos + (st2->size - el->target_pos);
        if (nb_moves < cheapest.nb_moves && el->pos < median_st1 && el->target_pos > median_st2)
            cheapest = (t_mvset) {nb_moves, UP, el->pos, DOWN, (st2->size - el->target_pos)};
        nb_moves = (st1->size - el->pos) + el->target_pos;
        if (nb_moves < cheapest.nb_moves)
            cheapest = (t_mvset) {nb_moves, UP, (st1->size - el->pos), UP, el->target_pos};
        el = el->next;
    }
    return(cheapest);
}
void    apply_mutual_moves(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb, t_mvset *mvset)
{
    if(mvset->way_st1 == UP)
    {
        while(mvset->mv_st1 > 0 && mvset->mv_st1 > 0)
        {
            operations_manager(a_pswap, sta, stb, "rr");
            mvset->mv_st1--;
            mvset->mv_st2--;
        }
    }
    else
    {
        while(mvset->mv_st1 > 0 && mvset->mv_st1 > 0)
        {
            operations_manager(a_pswap, sta, stb, "rrr");
            mvset->mv_st1--;
            mvset->mv_st2--;
        }
    }
}

//
void    apply_moveset(t_pswap *a_pswap, t_stconfig *st1, t_stconfig *st2, t_mvset mvset)
{
    
    
    
    while (mvset.mv_st1)
    {
        operations_manager(a_pswap, sta, stb, "rrr"); // on ne pourra pas connaitre le sens
        
        mvset->mv_st1--;
    }

    }
}

void	algo_big_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
    t_mvset cheapest;
    operations_manager(a_pswap, sta, stb, "pb");
    if(sta->size > 4)
	    operations_manager(a_pswap, sta, stb, "pb");
    while(sta->size > 0)
    {
        update_pos_and_target(sta->top, *stb, 0);
        cheapest = find_cheapest_moveset(a_pswap, sta, stb);
        if(mvset.way_st1 == mvset.way_st2)
            apply_mutual_moves(a_pswap, sta, stb, &mvset);
    }
    ////////
    while(stb->size > 0)
    {
        update_pos_and_target(stb->top, *sta, 1);
        cheapest = find_cheapest_moveset(a_pswap, stb, sta);
        if(mvset.way_st1 == mvset.way_st2)
            apply_mutual_moves(a_pswap, sta, stb, &mvset);
    }
    
    
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
