NAME = builtin_test
HEADER = builtin.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS = 	create_env_list.c \
		free_splits_and_env.c \
		libft_functions.c \
		export_cmd.c \
		export_utils.c \
		utils.c \
		main.c \

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all