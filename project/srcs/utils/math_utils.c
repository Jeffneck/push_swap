/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:10:50 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 15:12:02 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	return_max_int(int nb1, int nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

int	return_min_int(int nb1, int nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}

int	absolute(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
