/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:49 by hanglade          #+#    #+#             */
/*   Updated: 2024/01/15 16:33:03 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stinfo
{
	int		size;
	int		median;
}	t_stinfo;

typedef struct s_mvset
{
	int		nb_moves;
	int		mv_a;
	int		mv_b;
}	t_mvset;

typedef struct s_stelem
{
	int				data;
	int				pos;
	int				target_pos;
	struct s_stelem	*prev;
	struct s_stelem	*next;
}	t_stelem;

typedef struct s_stconfig
{
	t_stelem	*top;
	t_stelem	*bot;
	t_stinfo	info;

}	t_stconfig;

typedef struct s_pswap
{
	char		**c2_args;
	char		*checker;
	int			nb_args;
	char		**curr_operations;
	t_stconfig	*sta;
	t_stconfig	*stb;
}	t_pswap;

//CLOSING
int			exit_error(char *strerr);
void		close_program(t_pswap *a_pswap, char *strerr);

//INIT
//extract_args.c
void		verify_args_format(t_pswap *a_pswap, int nb_args, char **args);
void		extract_args(t_pswap *a_pswap, int argc, char **argv);

//stack_init.c
t_stelem	*create_stelem(int data);
void		stack_push_front(t_pswap *a_pswap, t_stconfig *st, int data);
void		fill_stack_a(t_pswap *a_pswap, t_stconfig *sta,
				char **c2_args, int nb_args);
void		init_stacks(t_pswap *a_pswap);

//SORTING_ALGOS
//big_algo_moves.c
t_mvset		find_elem_cheapest_moveset(t_stelem el, t_stinfo i_st1,
				t_stinfo i_st2);
t_mvset		find_cheapest_moveset(t_stconfig *st1, t_stconfig *st2, bool mode);
int			determine_step(ssize_t nb);
void		apply_double_moves(t_pswap *a_pswap,
				t_stconfig *sta, t_stconfig *stb, t_mvset *mvset);
void		apply_moves(t_pswap *a_pswap,
				t_stconfig *sta, t_stconfig *stb, t_mvset mvset);

//big_algo_targets.c
int			closest_smaller_pos(int obj, t_stconfig st_target);
int			closest_bigger_pos(int obj, t_stconfig st_target);
void		update_pos_and_target(t_stelem *el, t_stconfig st2, bool mode);
void		push_targets_stb(t_pswap *a_pswap, t_stconfig *sta,
				t_stconfig *stb);
void		ensure_sorted_sta(t_pswap *a_pswap, t_stconfig *sta);

//sorting_algos.c
void		algo_3_stack(t_pswap *a_pswap, t_stconfig *sta);
void		algo_big_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb);
void		sort_stack(t_pswap *a_pswap, t_stconfig *sta, t_stconfig *stb);

//STACK_OPERATIONS
//manage_operations.c
int			operation_exists(char *operation);
void		operations_manager(t_pswap *a_pswap, t_stconfig *sta,
				t_stconfig *stb, char *str_ops);

//manage_operations2.c
void		swap_manager(t_stconfig *stA, t_stconfig *stB, char *operation);
void		push_manager(t_stconfig *stA, t_stconfig *stB, char *operation);
void		rotate_manager(t_stconfig *stA, t_stconfig *stB, char *operation);
void		reverse_rotate_manager(t_stconfig *stA, t_stconfig *stB,
				char *operation);

//operations.c
void		swap_top_stack(t_stconfig *st);
void		push_st1_to_st2(t_stconfig *st1, t_stconfig *st2);
void		reverse_rotate_st(t_stconfig *st);
void		rotate_st(t_stconfig *st);

//UTILS
//math_utils.c
int			return_max_int(int nb1, int nb2);
int			return_min_int(int nb1, int nb2);
int			absolute(int nb);

//stack_utils.c
int			pos_min_stack(t_stconfig st);
int			pos_max_stack(t_stconfig st);
int			min_in_stack(t_stconfig st);
int			max_in_stack(t_stconfig st);

//stack_utils2.c
void		free_stack(t_stconfig *st);
int			is_duplicata(int nb, t_stconfig *sta);
void		update_stinfo(t_stconfig *st1, t_stconfig *st2);
int			stack_is_sorted(t_stconfig *st);

#endif //PUSH_SWAP_H
