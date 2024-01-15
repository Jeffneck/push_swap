/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:01 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 15:58:00 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stconfig *st)
{
	t_stelem	*curr;
	t_stelem	*tmp;

	curr = st->top;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	free(st);
}

int	is_duplicata(int nb, t_stconfig *sta)
{
	t_stelem	*curr;

	curr = sta->top;
	while (curr)
	{
		if (nb == curr->data)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	update_stinfo(t_stconfig *st1, t_stconfig *st2)
{
	st1->info.size--;
	st1->info.median = (st1->info.size) / 2;
	st2->info.size++;
	st2->info.median = (st2->info.size) / 2;
}

int	stack_is_sorted(t_stconfig *st)
{
	t_stelem	*curr;
	t_stelem	*next;

	if (st->info.size == 1)
		return (1);
	curr = st->top;
	next = curr->next;
	while (next)
	{
		if (curr->data > next->data)
			return (0);
		curr = curr->next;
		next = next->next;
	}
	return (1);
}
