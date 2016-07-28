NAME  = mysh
SRC = 	main.c \
	minishell.c \
	cmd_to_wordtab.c \
	utils_tab1.c \
	utils_tab2.c \
	utils_label.c \
	utils_label2.c \
	utils_str.c \
	builtin.c \
	my_setenv.c \
	my_unsetenv.c \
	my_env.c \
	my_cd.c \
	my_getcwd.c \
	exec_cmd.c \
	my_str_to_wordtab2.c \
	get_next_line.c \
	my_putstr.c \
	my_putchar.c \
	my_strlen.c \
	my_put_error.c \
	my_strcat.c \
	my_strncat.c \
	my_strcmp.c \
	my_strncmp.c \
	my_strcpy.c \
	my_strncpy.c \
	my_show_to_wordtab.c \
	my_strdup.c
OBJ = $(SRC:.c=.o)
CFLAGS += -W -Wall -pedantic -ansi -I.
##LIB = -L/u/all/sundas_c/rendu/lib/my -lmy
RM = rm -f
CC = gcc

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

all : $(NAME) 

clean : 
	$(RM) $(OBJ)
	$(RM) *~
fclean : clean
	$(RM) $(NAME)

re : fclean all