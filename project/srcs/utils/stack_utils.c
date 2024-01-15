/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:12:08 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 15:57:44 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pos_min_stack(t_stconfig st)
{
	t_stelem	*current;
	int			pos_min;
	int			min;
	int			i;

	if (!st.top)
		return (-1);
	pos_min = 0;
	i = 0;
	current = st.top;
	min = current->data;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			pos_min = i;
		}
		current = current->next;
		i++;
	}
	return (pos_min);
}

int	pos_max_stack(t_stconfig st)
{
	t_stelem	*current;
	int			pos_max;
	int			max;
	int			i;

	if (!st.top)
		return (-1);
	pos_max = 0;
	i = 0;
	current = st.top;
	max = current->data;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			pos_max = i;
		}
		current = current->next;
		i++;
	}
	return (pos_max);
}

int	min_in_stack(t_stconfig st)
{
	t_stelem	*current;
	int			min;

	if (!st.top)
		return (0);
	current = st.top;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

int	max_in_stack(t_stconfig st)
{
	t_stelem	*current;
	int			max;

	if (!st.top)
		return (0);
	current = st.top;
	max = current->data;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}
