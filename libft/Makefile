NAME = libft.a

INCLUDES = ./includes

SRC =   ft_atoi.c ft_bzero.c ft_isalnum.c \
        ft_isalpha.c ft_strnlen.c ft_isascii.c \
        ft_isdigit.c ft_isprint.c ft_itoa.c \
        ft_strrealloc.c ft_lstadd.c ft_lstdel.c \
        ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
        ft_splitdel.c ft_lstnew.c ft_memalloc.c \
        ft_memccpy.c ft_memchr.c ft_memcmp.c \
        ft_memcpy.c ft_memdel.c ft_memmove.c \
        ft_memset.c ft_putchar.c ft_putchar_fd.c \
        ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
        ft_putnbr_fd.c ft_putstr.c ft_strjoinch.c \
        ft_putstr_fd.c ft_strcat.c ft_strchr.c \
        ft_strclr.c ft_strcmp.c ft_strcpy.c \
        ft_strdel.c ft_strdup.c ft_strequ.c \
        ft_striter.c ft_striteri.c ft_strjoin.c \
        ft_strlcat.c ft_strlen.c ft_strmap.c \
        ft_strmapi.c ft_strncat.c ft_strncmp.c \
        ft_strncpy.c ft_strnequ.c ft_strnew.c \
        ft_strnstr.c ft_strrchr.c ft_strsplit.c \
        ft_strstr.c ft_strsub.c ft_strtrim.c \
        ft_tolower.c ft_toupper.c ft_swapint.c \
        get_next_line.c ft_countwords.c ft_lstrev.c \
        ft_lstcount.c ft_doubleptrdel.c \
        ft_printf.c print_str.c print.c \
        utils.c parse_opt.c print_nbr.c \
        print_wchar.c itoa_utils.c print_wstr.c \
        split_utils.c ft_strisdigit.c ft_atof.c \
        t_vector_logic.c \

CC	= clang

OBJ_DIR = obj

FLG = -Werror -Wextra -Wall

OBJ = $(SRC:.c=.o)

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@ar rc $(NAME) $(OBJ_SRC)
	@ranlib $(NAME)
	@echo "libft ✅"

$(OBJ_DIR)/%.o : %.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -I$(INCLUDES) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
