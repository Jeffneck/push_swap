SRCS	=	srcs/main.c\
			srcs/misc.c\
			srcs/manage_stelem.c\
			srcs/manage_errors.c\
			srcs/process_args.c\
			srcs/sorting_algo.c\
			srcs/stack_operations.c\
			srcs/stack_utils.c\
			# srcs/create_stack.c\
			# srcs/push_swap.c\

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

INC		=	-I ./includes

FLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

#faire en sorte que si le fichiers .c ou .o de la libft ou si libft.a n' existe pas 
LIB		=	-L ./libft -l ft

%.o	:		%.c $(INC)
	$(CC) $(FLAGS) $(INC) $(LIB)-c $< -o $@

$(NAME)	:	$(OBJS)
	make -C ./libft
	$(CC) $(FLAGS) $(INC) $(OBJS) -o $(NAME) $(LIB)

all		:		$(NAME)

clean	:
	rm -rf $(OBJS)
fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re