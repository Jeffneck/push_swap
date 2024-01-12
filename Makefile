SRCS	=	srcs/main.c\
			srcs/stack_init.c\
			srcs/manage_stelem.c\
			srcs/manage_errors.c\
			srcs/process_args.c\
			srcs/sorting_algo.c\
			srcs/operations.c\
			srcs/manage_operations.c\
			srcs/stack_utils.c\
			srcs/stack_utils2.c\

SRCS_BONUS = checker/checker.c \
			srcs/stack_init.c\
			srcs/manage_stelem.c\
			srcs/manage_errors.c\
			srcs/process_args.c\
			srcs/sorting_algo.c\
			srcs/operations.c\
			srcs/manage_operations.c\
			srcs/stack_utils.c\
			srcs/stack_utils2.c\

OBJS	=	$(SRCS:%.c=%.o)

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC		=	gcc

INC		=	includes/push_swap.h

FLAGS_INC	= -I includes/ -I libft/

FLAGS_LIB	= -L libft -lft

FLAGS	=	-Wall -Wextra -Werror -g3

NAME	=	push_swap

LIB		=	libft/libft.a

%.o	:		%.c  $(LIB) $(INC)
	$(CC) $(FLAGS) $(FlAGS_LIB) $(FLAGS_INC) -c $< -o $@

$(NAME)	:	$(OBJS) Makefile $(INC) $(LIB)
	make -C libft
	$(CC) $(FLAGS) $(INC) $(OBJS) $(LIB) -o $(NAME) 

all		:		$(NAME)

bonus	:	$(OBJS_BONUS) Makefile $(INC) $(LIB)
	make -C libft
	$(CC) $(FLAGS) $(INC) $(OBJS_BONUS) $(LIB) -o checker/checker

libft	:
	make -C libft

$(LIB)	:
	make -C libft

clean	:
	rm -rf $(OBJS)
	make clean -C ./libft

fclean	:	clean
	rm -rf $(NAME)
	make fclean -C ./libft

re		:	fclean all

.PHONY	:	all clean fclean re libft

