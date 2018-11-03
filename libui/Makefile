NAME = libui.a

# <=== LIBS ===>

LIBFT_NAME = libft.a

# <=== DIR PATHS ===>

SRC_PATH = ./src
INC_PATH = ./inc
LIB_PATH = ../libft/

# <=== SOURCES ===>

SRC =   func.c \

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# <=== COMPILER ===>

CC = clang

FLG = -O3 -Werror -Wextra -Wall

INCLUDES	=	-I../frameworks/SDL2.framework/Versions/A/Headers \
				-I../frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I../frameworks/SDL2_image.framework/Versions/A/Headers \
				-I../frameworks/SDL2_mixer.framework/Headers \
				-I../frameworks/SDL2_net.framework/Headers \
				-F../frameworks

# <=== CMDs ===>

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@ar rc $(NAME) $(OBJ_SRC)
	@ranlib $(NAME)
	@echo "libui ✅"

$(OBJ_DIR)/%.o : ./src/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all