NAME = guimp

# <=== LIBS ===>

LIBFT_NAME = libft.a
LIBUI_NAME = libui.a

# <=== DIR PATHS ===>

SRC_PATH = ./src
INC_PATH = ./inc
LIB_PATH = ../libft/
LIBUI_PATH = ../libui/

# <=== SOURCES ===>

SRC =   main.c \

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# <=== COMPILER ===>

CC = clang

FLG = -O3 -Werror -Wextra -Wall -I$(LIB_PATH)includes -I$(LIBUI_PATH)inc -I./inc

CGFLAGS =		-framework OpenGL -framework AppKit
INCLUDES	=	-I../frameworks/SDL2.framework/Versions/A/Headers \
				-I../frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I../frameworks/SDL2_image.framework/Versions/A/Headers \
				-I../frameworks/SDL2_mixer.framework/Headers \
				-I../frameworks/SDL2_net.framework/Headers \
				-F../frameworks
FRAMEWORKS	=	-F../frameworks \
				-rpath ../frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer -framework SDL2_net

# <=== CMDs ===>

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@make -C $(LIB_PATH)
	@make -C $(LIBUI_PATH)
	@$(CC) $(FLG) $(CGFLAGS) $(FRAMEWORKS) -g $(LIB_PATH)$(LIBFT_NAME) -g $(LIBUI_PATH)$(LIBUI_NAME) $(OBJ_SRC) -o $(NAME)
	@echo "GUImp ✅"

$(OBJ_DIR)/%.o : ./src/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -c -I$(INC) -c $(INCLUDES) -c -o $@ $<
	@echo "./src ✅"

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean
	@make -C $(LIBUI_PATH) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@make -C $(LIBUI_PATH) fclean

re: fclean all