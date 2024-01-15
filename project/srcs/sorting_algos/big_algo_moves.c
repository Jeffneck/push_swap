/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:35:05 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 15:11:30 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_mvset	find_elem_cheapest_moveset(t_stelem el, t_stinfo i_st1, t_stinfo i_st2)
{
	int	nb_moves;
	int	el_moves;
	int	target_moves;

	el_moves = el.pos;
	if (el.pos > i_st1.median)
		el_moves = el.pos - i_st1.size;
	target_moves = el.target_pos;
	if (el.target_pos > i_st2.median)
		target_moves = el.target_pos - i_st2.size;
	nb_moves = absolute(el_moves) + absolute(target_moves);
	if ((el_moves > 0 && target_moves > 0))
		nb_moves = return_max_int(el_moves, target_moves);
	else if (el_moves < 0 && target_moves < 0)
		nb_moves = return_min_int(el_moves, target_moves);
	return ((t_mvset){nb_moves, el_moves, target_moves});
}

t_mvset	find_cheapest_moveset(t_stconfig *st1, t_stconfig *st2, bool mode)
{
	t_stelem	*el;
	t_mvset		global_cheapest;
	t_mvset		tmp;

	el = st1->top;
	global_cheapest = (t_mvset){INT_MAX, INT_MAX, INT_MAX};
	while (el)
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
	return (global_cheapest);
}

int	determine_step(ssize_t nb)
{
	if (nb > 0)
		return (-1);
	else if (nb < 0)
		return (1);
	else
		return (0);
}

void	apply_double_moves(t_pswap *a_pswap,
	t_stconfig *sta, t_stconfig *stb, t_mvset *mvset)
{
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

void	apply_moves(t_pswap *a_pswap,
	t_stconfig *sta, t_stconfig *stb, t_mvset mvset)
{
	int	step_st1;
	int	step_st2;

	step_st1 = determine_step(mvset.mv_a);
	step_st2 = determine_step(mvset.mv_b);
	apply_double_moves(a_pswap, sta, stb, &mvset);
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
