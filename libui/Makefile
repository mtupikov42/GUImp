NAME = libui.a

OS = $(shell uname)

# <=== LIBS ===>

LIBFT_NAME = libft.a

# <=== DIR PATHS ===>

SRC_WINDOWS_PATH = ./src/windows/
SRC_EVENTS_PATH = ./src/events/
SRC_ITEMS_PATH = ./src/items/
SRC_UTILS_PATH = ./src/utils/

INC_PATH = ./inc/
LIB_PATH = ../libft/

# <=== SOURCES ===>

SRC_WINDOWS =   empty_window.c \

SRC_EVENTS =    standart_event_handler.c \

SRC_ITEMS =     button.c \

SRC_UTILS =     g_assert.c \

# <=== OBJ ===>

OBJ_DIR = obj

OBJ_SRC_WINDOWS = $(addprefix $(OBJ_DIR)/, $(SRC_WINDOWS:.c=.o))

OBJ_SRC_EVENTS = $(addprefix $(OBJ_DIR)/, $(SRC_EVENTS:.c=.o))

OBJ_SRC_ITEMS = $(addprefix $(OBJ_DIR)/, $(SRC_ITEMS:.c=.o))

OBJ_SRC_UTILS = $(addprefix $(OBJ_DIR)/, $(SRC_UTILS:.c=.o))

# <=== COMPILER ===>

CC = clang

FLG = -O3 -Werror -Wextra -Wall -I$(LIB_PATH)includes

ifeq ($(OS), Linux)
	FRAMEWORKS	:=	`pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm -lOpenCL
else
	INCLUDES	=	-I../frameworks/SDL2.framework/Versions/A/Headers \
					-I../frameworks/SDL2_ttf.framework/Versions/A/Headers \
					-I../frameworks/SDL2_image.framework/Versions/A/Headers \
					-I../frameworks/SDL2_mixer.framework/Headers \
					-I../frameworks/SDL2_net.framework/Headers \
					-F../frameworks
endif

# <=== RULES ===>

all: $(NAME)

$(NAME): $(OBJ_SRC_WINDOWS) $(OBJ_SRC_EVENTS) $(OBJ_SRC_ITEMS) $(OBJ_SRC_UTILS)
	@ar -x $(LIB_PATH)$(LIBFT_NAME)
	@ar rc $(NAME) $(OBJ_SRC_WINDOWS) $(OBJ_SRC_EVENTS) $(OBJ_SRC_ITEMS) $(OBJ_SRC_UTILS) *.o
	@rm -f *.o '__.SYMDEF SORTED'
	@ranlib $(NAME)
	@echo "libui ✅"

$(OBJ_DIR)/%.o : $(SRC_WINDOWS_PATH)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) $(FRAMEWORKS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_EVENTS_PATH)%.c
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) $(FRAMEWORKS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_ITEMS_PATH)%.c
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) $(FRAMEWORKS) -c -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_UTILS_PATH)%.c
	@$(CC) $(FLG) -c -I$(INC_PATH) -c $(INCLUDES) $(FRAMEWORKS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all