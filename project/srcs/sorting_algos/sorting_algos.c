/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:41:51 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 15:58:56 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algo_3_stack(t_pswap *a_pswap, t_stconfig *sta)
{
	if (pos_min_stack(*sta) == 0)
	{
		if (pos_max_stack(*sta) == 2)
			return ;
		else
			operations_manager(a_pswap, sta, a_pswap->stb, "sa,ra");
	}
	else if (pos_max_stack(*sta) == 0)
	{
		if (pos_min_stack(*sta) == 1)
			operations_manager(a_pswap, sta, a_pswap->stb, "ra");
		else
			operations_manager(a_pswap, sta, a_pswap->stb, "sa,rra");
	}
	else
	{
		if (pos_min_stack(*sta) == 1)
			operations_manager(a_pswap, sta, a_pswap->stb, "sa");
		else
			operations_manager(a_pswap, sta, a_pswap->stb, "rra");
	}
}

void	algo_big_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
	t_mvset	cheapest;

	push_targets_stb(a_pswap, sta, stb);
	while (sta->info.size > 3)
	{
		update_pos_and_target(sta->top, *stb, 0);
		cheapest = find_cheapest_moveset(sta, stb, 0);
		apply_moves(a_pswap, sta, stb, cheapest);
		operations_manager(a_pswap, sta, stb, "pb");
	}
	algo_3_stack(a_pswap, sta);
	while (stb->info.size > 0)
	{
		update_pos_and_target(stb->top, *sta, 1);
		cheapest = find_cheapest_moveset(stb, sta, 1);
		apply_moves(a_pswap, sta, stb, cheapest);
		operations_manager(a_pswap, sta, stb, "pa");
	}
	ensure_sorted_sta(a_pswap, sta);
}

void	sort_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
	if (sta->info.size <= 3)
		algo_3_stack(a_pswap, sta);
	else
		algo_big_stack(a_pswap, sta, stb);
}
