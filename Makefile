NAME = minishell

INCLUDES = ./includes
RL_INCLUDE = -I/Users/${USER}/.brew/opt/readline/include
INRL = -L/Users/${USER}/.brew/opt/readline/lib

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
	@cc $(CFLAGS) -c -o $@ $< -I $(INCLUDES) $(RL_INCLUDE)

$(NAME) : $(OBJS)
	@make -C $(LIBFTDIR)
	@cc $(CFLAGS) $(RL_INCLUDE) $(INRL) $(INLIBFT) -o $@ $^ -lreadline
	@echo "make finish"

clean :
	@make -C $(LIBFTDIR) clean
	@rm -f $(OBJS)
	@echo "clean finish"

fclean : clean
	@make -C $(LIBFTDIR) fclean
	@rm -f $(NAME)
	@echo "fclean finish"

re : fclean all

.PHONY : clean fclean re all
