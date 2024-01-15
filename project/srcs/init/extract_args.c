/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:16:17 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 15:11:16 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	verify_args_format(t_pswap *a_pswap, int nb_args, char **args)
{
	int	i;
	int	j;
	int	len_nbr;

	i = -1;
	while (++i < nb_args)
	{
		len_nbr = 0;
		j = 0;
		while (ft_isspace(args[i][j]))
			j++;
		if (ft_issign(args[i][j]))
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				close_program(a_pswap, "Error\n");
			if (len_nbr > 10)
				close_program(a_pswap, "Error\n");
			len_nbr++;
			j++;
		}
		if (len_nbr == 0)
			close_program(a_pswap, "Error\n");
	}
}

void	extract_args(t_pswap *a_pswap, int argc, char **argv)
{
	size_t	size_stack;

	if (argc == 2)
		a_pswap->c2_args = ft_split(argv[1], ' ');
	else
		a_pswap->c2_args = char2dup(&argv[1]);
	if (!a_pswap->c2_args)
		close_program(a_pswap, "Error\n");
	size_stack = char2len(a_pswap->c2_args);
	if (size_stack > (size_t)INT_MAX)
		close_program(a_pswap, "Error\n");
	a_pswap->nb_args = (int) size_stack;
}
