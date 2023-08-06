CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ${wildcard *.c}

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(TOTAL_OBJS)
	@ar -rc $@ $^

bonus :
	@make WITH_BONUS=1 all

clean: 
	@rm -f $(OBJS) $(OBJS_B)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
