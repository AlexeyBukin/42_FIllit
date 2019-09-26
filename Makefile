NAME = fillit

FLAGS = -Wall -Wextra -Werror

H_FILES = includes/fillit_header.h

O_DIR = objects/
LIB_DIR = Libft/
LIB_HEAD = $(LIB_DIR)libft.h
LIB_MAKE = $(LIB_DIR)Makefile
LIB_FILE = lib/libft.a

#copypaste from bash "ls *.c" below
C_FILES_LIST = define_tetrimino.c main.c shift.c print.c fit.c read.c start.c

C_FILES = $(C_FILES_LIST)

O_FILES_LIST = $(patsubst %.c, %.o, $(C_FILES_LIST))
O_FILES	= $(addprefix $(O_DIR), $(O_FILES_LIST))

.PHONY: clean fclean

.PRECIOUS: $(TEST_OBJ_DIR)%.o

all: $(NAME)


$(NAME): $(O_DIR) $(O_FILES) $(LIB_FILE)
	clang -o $(NAME) $(O_FILES) -I Libft/includes -I includes/ -L lib/ -lft

$(LIB_FILE): $(O_DIR)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)libft.a $(LIB_FILE)

$(O_DIR):
	@mkdir -p $(O_DIR)

$(O_DIR)%.o: %.c
	clang -Wall -Wextra -Werror -I $(LIB_DIR) -o $@ -c $<

clean:
	@rm -rf $(O_DIR)
	@rm -f $(LIB_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

#fast output of variable
#print-%  : ; @echo $* = $($*)