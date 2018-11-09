#ifndef GUIMP_T_FONT_H
# define GUIMP_T_FONT_H

#include <SDL_ttf.h>

typedef struct	s_font
{
	char 		*name;
	size_t 		size;
	TTF_Font	*font;
}				t_font;

typedef struct	s_font_data
{
	char 		*name;
	char 		*text;
	size_t 		size;
	SDL_Color	color;
}				t_font_data;

typedef struct	s_font_render
{
	t_font		*font;
	t_font_data	data;
	SDL_Surface	*dest_surface;
	SDL_Rect	font_pos;
}				t_font_render;

#endif
