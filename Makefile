NAME = minishell

INCLUDES = ./includes
RL_INCLUDE = -I/opt/homebrew/Cellar/readline/8.2.1/include
INRL = -L/opt/homebrew/Cellar/readline/8.2.1/lib
  
EXECUTE_SRCS = ${wildcard ./srcs/execute/*.c}
PARSE_SRCS = ${wildcard ./srcs/parse/*.c}
UTILS_SRCS = ${wildcard ./srcs/utils/*.c}

SRCS := ${EXECUTE_SRCS} \
		${PARSE_SRCS} \
		${UTILS_SRCS} \
		./srcs/main.c

LIBFTDIR = ./libft
INLIBFT = -L./libft -lft

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	cc $(CFLAGS) -c -o $@ $< -I $(INCLUDES) $(RL_INCLUDE)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	cc $(CFLAGS) $(RL_INCLUDE) $(INRL) $(INLIBFT) -o $@ $^ -lreadline

clean :
	make -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all
