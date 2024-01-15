/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:40:04 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 16:40:05 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	do_commands(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb)
{
	char	*line;
	line = a_pswap->checker; 
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		line[ft_strlen(line) - 1] = '\0';
		operations_manager(a_pswap, sta, stb, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_pswap pswap;
	ft_bzero(&pswap, sizeof(t_pswap));
	init_stacks(&pswap);
	if (argc < 2)
		close_program(&pswap, NULL);
	extract_args(&pswap, argc, argv);
	verify_args_format(&pswap, pswap.nb_args, pswap.c2_args);
	fill_stack_a(&pswap, pswap.sta, pswap.c2_args, pswap.nb_args);
	if(stack_is_sorted(pswap.sta))
		close_program(&pswap, NULL);
	do_commands(&pswap, pswap.sta, pswap.stb);
	if(stack_is_sorted(pswap.sta))
		close_program(&pswap, "OK");
	close_program(&pswap, "KO");
	return (0);
}