NAME=libft.a

FLAGS=-Wall -Wextra -Werror

H_FILES = libft.h

O_DIR = objects/
TEST_SRC_DIR = test_src/
TEST_OBJ_DIR = test_obj/
TEST_BIN_DIR = test_bin/
TEST_FUNCS_C_FILE = test_src/test_funcs.c.test
TEST_FUNCS_O_FILE = test_obj/test_funcs.o

#copypaste from bash "ls *.c" below
C_FILES_LIST = ft_isalpha.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memccpy.c ft_memmove.c ft_memcmp.c ft_strlen.c \
ft_atoi.c ft_strcpy.c ft_strdup.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_strstr.c ft_strnstr.c ft_memalloc.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putstr.c ft_putendl.c ft_putchar.c ft_itoa.c ft_putnbr_fd.c \
ft_putnbr.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
ft_strfnr.c ft_strcfnr.c ft_abs.c ft_pow.c ft_word_count.c ft_lstappend.c

C_FILES = $(C_FILES_LIST)

O_FILES_LIST = $(patsubst %.c, %.o, $(C_FILES_LIST))
O_FILES	= $(addprefix $(O_DIR), $(O_FILES_LIST))

TEST_C_FILES_LIST = $(patsubst %.c, %_test.c.test, $(C_FILES_LIST))
TEST_C_FILES	= $(addprefix $(TEST_SRC_DIR), $(TEST_C_FILES_LIST))

TEST_O_FILES_LIST = $(patsubst %.c, %_test.o, $(C_FILES_LIST))
TEST_O_FILES	= $(addprefix $(TEST_OBJ_DIR), $(TEST_O_FILES_LIST))

TEST_EXE_FILES_LIST = $(patsubst %.c, %_test.run, $(C_FILES_LIST))
TEST_EXE_FILES	= $(addprefix $(TEST_BIN_DIR), $(TEST_EXE_FILES_LIST))

.PHONY: clean fclean bclean tclean

.PRECIOUS: $(TEST_OBJ_DIR)%.o

all: $(NAME)

$(NAME): $(O_DIR) $(O_FILES)
	@ar rc $(NAME) $(O_FILES)
	@ranlib $(NAME)

$(O_DIR):
	@mkdir -p $(O_DIR)

$(O_DIR)%.o: %.c
	@gcc -c $(FLAGS) -o $@ $<

tc: $(TEST_BIN_DIR) $(TEST_OBJ_DIR) $(O_DIR) $(TEST_EXE_FILES)

$(TEST_BIN_DIR):
	@mkdir -p $(TEST_BIN_DIR)

$(TEST_OBJ_DIR):
	@mkdir -p $(TEST_OBJ_DIR)

$(TEST_OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c.test
	@gcc -c $(FLAGS) -x c -o $@ $<

$(TEST_BIN_DIR)%.run: $(TEST_OBJ_DIR)%.o $(O_FILES) $(TEST_FUNCS_O_FILE)
	@gcc $(FLAGS) -o $@ $^

tclean:
	@rm -rf $(TEST_OBJ_DIR)

bclean: tclean
	@rm -rf $(TEST_BIN_DIR)

clean: tclean
	@rm -rf $(O_DIR)

fclean: clean bclean
	@rm -f $(NAME)

re: fclean all

rt: fclean  tc

#fast output of variable
#print-%  : ; @echo $* = $($*)