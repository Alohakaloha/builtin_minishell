NAME = builtin_test
HEADER = builtin.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS = 	env/create_env_list.c \
		env/free_splits_and_env.c \
		export/export_cmd_0.c \
		export/export_cmd_1.c \
		export/export_utils.c \
		cd/cd.c \
		libft_functions.c \
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