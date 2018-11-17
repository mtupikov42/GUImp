NAME = guimp

OS = $(shell uname)

# <=== LIBS ===>

LIBFT_NAME = libft.a
LIBUI_NAME = libui.a

# <=== DIR PATHS ===>

SRC_PATH = ./src/
SRC_UTILS_PATH = ./src/utilities/
SRC_FONTS_PATH = ./src/fonts/
SRC_RENDER_PATH = ./src/render/
INC_PATH = ./inc/
LIB_PATH = ../libft/
LIBUI_PATH = ../libui/

# <=== SOURCES ===>

SRC =           main.c \
                main_loop.c \
                main_loop_events.c \

SRC_UTILS =     vector_utilities.c \
                general_utilities.c \
                initialization_utilities.c \
                parent_helpers.c \

SRC_FONTS =     fonts.c \

SRC_RENDER =    render.c \
                render_button.c \
                render_font.c \
                render_text_area.c \
                render_window.c \

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_SRC_UTILS = $(addprefix $(OBJ_DIR)/, $(SRC_UTILS:.c=.o))

OBJ_SRC_FONTS = $(addprefix $(OBJ_DIR)/, $(SRC_FONTS:.c=.o))

OBJ_SRC_RENDER = $(addprefix $(OBJ_DIR)/, $(SRC_RENDER:.c=.o))

# <=== COMPILER ===>

CC = clang

FLG = -O3 -Werror -Wextra -Wall -I$(LIB_PATH)includes -I$(LIBUI_PATH)inc -I$(INC_PATH)

ifeq ($(OS), Linux)
	FRAMEWORKS	:=	`pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm -lOpenCL
else
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
endif

# <=== RULES ===>

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_SRC_UTILS) $(OBJ_SRC_FONTS) $(OBJ_SRC_RENDER)
	@make -C $(LIB_PATH)
	@make -C $(LIBUI_PATH)
	@$(CC) $(FLG) $(CGFLAGS) $(FRAMEWORKS) -g $(LIB_PATH)$(LIBFT_NAME) -g $(LIBUI_PATH)$(LIBUI_NAME) \
	$(OBJ_SRC) $(OBJ_SRC_UTILS) $(OBJ_SRC_FONTS) $(OBJ_SRC_RENDER) -o $(NAME)
	@echo "GUImp ✅"

$(OBJ_DIR)/%.o : $(SRC_PATH)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_UTILS_PATH)%.c
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_FONTS_PATH)%.c
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_RENDER_PATH)%.c
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean
	@make -C $(LIBUI_PATH) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@make -C $(LIBUI_PATH) fclean

re: fclean all