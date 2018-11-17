#ifndef GUIMP_T_TEXT_AREA_H
# define GUIMP_T_TEXT_AREA_H

/*
**	INCLUDES
*/

# include "t_window.h"
# include "t_font.h"

/*
**	DEFINES
*/

# define LOAD_STD_TA_IDLE IMG_Load("resources/standart_button/standart_button_idle.png") // TODO standart text area png

/*
**	STRUCTS
*/

/*
** t_text_area
** type -> type of item
** properties -> SDL struct with x, y, width, height
** surface -> must not be null.
** font_data -> font utils struct.
*/

typedef struct	s_text_area
{
	int			type;
	void		*parent;
	SDL_Rect	properties;
	SDL_Surface *active_surface;
	t_font_data	font_data;
}				t_text_area;

typedef struct	s_text_area_info
{
	SDL_Rect	properties;
	SDL_Surface *active_surface;
	t_font_data	font_data;
	void		*parent;
}				t_text_area_info;

#endif
