/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:40:04 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/17 16:33:02 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	operations_manager_bonus(t_pswap *a_pswap, t_stconfig *sta,
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
		i++;
	}
	free_char2(&(a_pswap->curr_operations));
	a_pswap->curr_operations = NULL;
}

void	do_commands(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
	char	*line;

	line = a_pswap->checker;
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		line[ft_strlen(line) - 1] = '\0';
		operations_manager_bonus(a_pswap, sta, stb, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_pswap	pswap;

	ft_bzero(&pswap, sizeof(t_pswap));
	init_stacks(&pswap);
	if (argc < 2)
		close_program(&pswap, NULL);
	extract_args(&pswap, argc, argv);
	verify_args_format(&pswap, pswap.nb_args, pswap.c2_args);
	fill_stack_a(&pswap, pswap.sta, pswap.c2_args, pswap.nb_args);
	if (stack_is_sorted(pswap.sta))
		close_program(&pswap, NULL);
	do_commands(&pswap, pswap.sta, pswap.stb);
	if (stack_is_sorted(pswap.sta))
		close_program(&pswap, "OK");
	close_program(&pswap, "KO");
	return (0);
}
