/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:15:19 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 15:58:27 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stelem	*create_stelem(int data)
{
	t_stelem	*new_elem;

	new_elem = (t_stelem *) malloc(sizeof(t_stelem));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->pos = 0;
	new_elem->target_pos = 0;
	new_elem->prev = NULL;
	new_elem->next = NULL;
	return (new_elem);
}

void	stack_push_front(t_pswap *a_pswap, t_stconfig *st, int data)
{
	t_stelem	*new_elem;

	new_elem = create_stelem(data);
	if (new_elem == NULL)
		close_program(a_pswap, "Error\n");
	if (!st->top)
		st->bot = new_elem;
	else
	{
		new_elem->next = st->top;
		st->top->prev = new_elem;
	}
	st->top = new_elem;
	st->info.size++;
}

void	fill_stack_a(t_pswap *a_pswap, t_stconfig *sta,
	char **c2_args, int nb_args)
{
	long	nb;
	int		i;

	nb = 0;
	i = nb_args - 1;
	while (i >= 0)
	{
		nb = ft_atol(c2_args[i]);
		if (is_duplicata(nb, sta))
			close_program(a_pswap, "Error\n");
		if (nb > (long)INT_MAX || nb < (long)INT_MIN)
			close_program(a_pswap, "Error\n");
		stack_push_front(a_pswap, a_pswap->sta, (int)nb);
		i--;
	}
}

void	init_stacks(t_pswap *a_pswap)
{
	a_pswap->sta = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));
	if (!a_pswap->sta)
		close_program(a_pswap, "Error\n");
	a_pswap->stb = (t_stconfig *) ft_calloc(1, sizeof(t_stconfig));
	if (!a_pswap->stb)
		close_program(a_pswap, "Error\n");
}
