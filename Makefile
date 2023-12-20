SRCS	=	srcs/main.c\
			srcs/create_stack.c\
			srcs/process_args.c\
			srcs/stack_operations.c\
			srcs/stack_utils.c\

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

INC		=	-I./includes

FLAGS	=	-Wall -Wextra -Werror -g3

NAME	=	push_swap

%.o	:		%.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@
$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all		:		$(NAME)

clean	:
	rm -rf $(OBJS)
fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re