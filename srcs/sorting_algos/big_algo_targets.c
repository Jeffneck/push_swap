/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_targets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:52:08 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 15:11:36 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	closest_smaller_pos(int obj, t_stconfig st_target)
{
	t_stelem	*curr;
	int			target_pos;
	int			i;
	long		target;
	int			found;

	curr = st_target.top;
	target = -2147483650;
	target_pos = 0;
	i = 0;
	found = 0;
	while (curr)
	{
		if ((long) curr->data > target && obj > curr->data)
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

int	closest_bigger_pos(int obj, t_stconfig st_target)
{
	t_stelem	*curr;
	int			target_pos;
	int			i;
	long		target;
	int			found;

	curr = st_target.top;
	target = 2147483650;
	target_pos = 0;
	i = 0;
	found = 0;
	while (curr)
	{
		if ((long)curr->data < target && obj < curr->data)
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
	int	pos;

	pos = 0;
	while (el)
	{
		el->pos = pos;
		if (mode == 0)
			el->target_pos = closest_smaller_pos(el->data, st2);
		else
			el->target_pos = closest_bigger_pos(el->data, st2);
		pos++;
		el = el->next;
	}
}

void	push_targets_stb(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
	operations_manager(a_pswap, sta, stb, "pb");
	if (sta->info.size > 4)
		operations_manager(a_pswap, sta, stb, "pb");
}

void	ensure_sorted_sta(t_pswap *a_pswap, t_stconfig *sta)
{
	t_mvset	reset;

	ft_bzero(&reset, sizeof(t_mvset));
	reset.mv_a = pos_min_stack(*sta);
	if (reset.mv_a > sta->info.median)
		reset.mv_a = reset.mv_a - sta->info.size;
	apply_moves(a_pswap, sta, a_pswap->stb, reset);
}
