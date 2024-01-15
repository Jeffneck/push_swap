SRCS	=	srcs/main.c\
			\
			srcs/closing/closing.c\
			\
			srcs/init/stack_init.c\
			srcs/init/extract_args.c\
			\
			srcs/sorting_algos/sorting_algos.c\
			srcs/sorting_algos/big_algo_moves.c\
			srcs/sorting_algos/big_algo_targets.c\
			\
			srcs/stack_operations/manage_operations.c\
			srcs/stack_operations/manage_operations2.c\
			srcs/stack_operations/operations.c\
			\
			srcs/utils/stack_utils.c\
			srcs/utils/math_utils.c\
			srcs/utils/stack_utils2.c\

SRCS_BONUS = srcs/checker/checker.c \
			\
			srcs/closing/closing.c\
			\
			srcs/init/stack_init.c\
			srcs/init/extract_args.c\
			\
			srcs/sorting_algos/sorting_algos.c\
			srcs/sorting_algos/big_algo_moves.c\
			srcs/sorting_algos/big_algo_targets.c\
			\
			srcs/stack_operations/manage_operations.c\
			srcs/stack_operations/manage_operations2.c\
			srcs/stack_operations/operations.c\
			\
			srcs/utils/stack_utils.c\
			srcs/utils/math_utils.c\
			srcs/utils/stack_utils2.c\

OBJS	=	$(SRCS:%.c=%.o)

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC		=	gcc

INC		=	includes/push_swap.h

FLAGS_INC	= -I includes/ -I libft/

FLAGS_LIB	= -L libft -lft

FLAGS	=	-Wall -Wextra -Werror -g3

NAME	=	push_swap

NAME_BONUS	=	srcs/checker/checker

LIB		=	libft/libft.a

%.o	:		%.c  $(LIB) $(INC)
	$(CC) $(FLAGS) $(FlAGS_LIB) $(FLAGS_INC) -c $< -o $@

$(NAME)	:	$(OBJS) Makefile $(INC) $(LIB)
	$(CC) $(FLAGS) $(INC) $(OBJS) $(LIB) -o $(NAME)

$(NAME_BONUS)	:	$(OBJS_BONUS) Makefile $(INC) $(LIB)
	$(CC) $(FLAGS) $(INC) $(OBJS_BONUS) $(LIB) -o checker

$(LIB)	:	force
	make -C libft

all		:		$(NAME)

bonus	:		$(NAME_BONUS)

force	:

libft	: $(LIB)

clean	:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	make clean -C ./libft

fclean	:	clean
	rm -rf $(NAME)
	rm -rf checker
	make fclean -C ./libft

re		:	fclean all

.PHONY	:	all clean fclean re libft force

