cmake_minimum_required(VERSION 3.12)
project(GUImp C)

set(CMAKE_C_STANDARD 99)


add_executable(GUImp guimp-app/src/main.c guimp-app/inc/guimp.h libui/inc/libui.h libui/src/func.c)

target_include_directories(GUImp PRIVATE guimp-app/inc)
target_include_directories(GUImp PRIVATE libft/includes)
target_include_directories(GUImp PRIVATE libui/inc frameworks/SDL2 frameworks/SDL2.framework frameworks/SDL2_image.framework)
