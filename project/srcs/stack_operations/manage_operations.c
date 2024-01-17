/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:07:22 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/17 16:14:20 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	operation_exists(char *operation)
{
	char	*valid_op[11];
	size_t	num_valid_op;
	size_t	i;

	valid_op[0] = "sa";
	valid_op[1] = "sb";
	valid_op[2] = "ss";
	valid_op[3] = "pa";
	valid_op[4] = "pb";
	valid_op[5] = "ra";
	valid_op[6] = "rb";
	valid_op[7] = "rr";
	valid_op[8] = "rra";
	valid_op[9] = "rrb";
	valid_op[10] = "rrr";
	i = 0;
	num_valid_op = sizeof(valid_op) / sizeof(valid_op[0]);
	while (i < num_valid_op)
	{
		if (ft_strcmp(operation, valid_op[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	operations_manager(t_pswap *a_pswap, t_stconfig *sta,
	t_stconfig *stb, char *str_ops)
{
	size_t	i;
	char	**operations;

	i = 0;
	operations = ft_split(str_ops, ',');
	a_pswap->curr_operations = operations;
	if (!operations)
		close_program(a_pswap, "Error\n");
	while (operations[i])
	{
		if (!operation_exists(operations[i]))
			close_program(a_pswap, "Error\n");
		if (operations[i][0] == 's')
			swap_manager(sta, stb, operations[i]);
		else if (operations[i][0] == 'p')
			push_manager(sta, stb, operations[i]);
		else if (operations[i][0] == 'r' && ft_strlen(operations[i]) == 2)
			rotate_manager(sta, stb, operations[i]);
		else
			reverse_rotate_manager(sta, stb, operations[i]);
		ft_printf("%s\n", operations[i]);
		i++;
	}
	free_char2(&(a_pswap->curr_operations));
	a_pswap->curr_operations = NULL;
}
