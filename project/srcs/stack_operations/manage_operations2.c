/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:59:52 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 16:00:11 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
	if (ft_strcmp(operation, "sa") == 0)
		swap_top_stack(stA);
	else if (ft_strcmp(operation, "sb") == 0)
		swap_top_stack(stB);
	else if (ft_strcmp(operation, "ss") == 0)
	{
		swap_top_stack(stA);
		swap_top_stack(stB);
	}
}

void	push_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
	if (ft_strcmp(operation, "pa") == 0)
		push_st1_to_st2(stB, stA);
	else if (ft_strcmp(operation, "pb") == 0)
		push_st1_to_st2(stA, stB);
}

void	rotate_manager(t_stconfig *stA, t_stconfig *stB, char *operation)
{
	if (ft_strcmp(operation, "ra") == 0)
		rotate_st(stA);
	else if (ft_strcmp(operation, "rb") == 0)
		rotate_st(stB);
	else if (ft_strcmp(operation, "rr") == 0)
	{
		rotate_st(stA);
		rotate_st(stB);
	}
}

void	reverse_rotate_manager(t_stconfig *stA, t_stconfig *stB,
	char *operation)
{
	if (ft_strcmp(operation, "rra") == 0)
		reverse_rotate_st(stA);
	else if (ft_strcmp(operation, "rrb") == 0)
		reverse_rotate_st(stB);
	else if (ft_strcmp(operation, "rrr") == 0)
	{
		reverse_rotate_st(stA);
		reverse_rotate_st(stB);
	}
}
