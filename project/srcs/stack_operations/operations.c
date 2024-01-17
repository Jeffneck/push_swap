/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:14:20 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/17 15:00:16 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap_top_stack(t_stconfig *st)
{
	t_stelem	tmp;
	t_stelem	*first;
	t_stelem	*second;
	t_stelem	*third;

	if (!st || !st->top || !st->top->next)
		return (0);
	first = st->top;
	second = first->next;
	third = second->next;
	ft_memcpy(&tmp, second, sizeof(t_stelem));
	if (st->top == NULL || st->top == st->bot)
		return (0);
	second->next = first;
	second->prev = NULL;
	first->next = tmp.next;
	first->prev = second;
	st->top = second;
	if (st->info.size == 2)
		st->bot = first;
	if (st->info.size > 2)
		third->prev = first;
	return (1);
}

int	push_st1_to_st2(t_stconfig *st1, t_stconfig *st2)
{
	t_stelem	*top_s1;
	t_stelem	*top_s2;
	t_stelem	*next_s1;

	if (!st1 || !st2 || !st1->top)
		return (0);
	top_s1 = st1->top;
	next_s1 = top_s1->next;
	top_s2 = st2->top;
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
	return (1);
}

int	reverse_rotate_st(t_stconfig *st)
{
	t_stelem	*top;
	t_stelem	*bot;
	t_stelem	*prev_bot;

	top = st->top;
	bot = st->bot;
	prev_bot = st->bot->prev;
	if (!st || !st->top || !st->top->next)
		return (0);
	bot->prev = NULL;
	bot->next = top;
	top->prev = bot;
	prev_bot->next = NULL;
	st->top = bot;
	st->bot = prev_bot;
	return (1);
}

int	rotate_st(t_stconfig *st)
{
	t_stelem	*top;
	t_stelem	*top_next;
	t_stelem	*bot;

	top = st->top;
	top_next = top->next;
	bot = st->bot;
	if (!st || !st->top || !st->top->next)
		return (0);
	top_next->prev = NULL;
	bot->next = top;
	top->next = NULL;
	top->prev = bot;
	st->top = top_next;
	st->bot = top;
	return (1);
}
