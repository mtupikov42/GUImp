#ifndef GUIMP_T_BUTTON_ITEM_H
# define GUIMP_T_BUTTON_ITEM_H

/*
**	INCLUDES
*/

# include <SDL.h>
# include <stdbool.h>
# include "e_items.h"
# include "t_sdl_events.h"
# include "t_window.h"
#include "t_font.h"

/*
**	DEFINES
*/

# define LOAD_STD_BTN_IDLE IMG_Load("resources/standart_button/standart_button_idle.png")
# define LOAD_STD_BTN_HOV IMG_Load("resources/standart_button/standart_button_hovered.png")
# define LOAD_STD_BTN_PRS IMG_Load("resources/standart_button/standart_button_pressed.png")

/*
**	STRUCTS
*/

/*
** t_button
** type -> type of item
** is_hovered, is_pressed -> obviously.
** properties -> SDL struct with x, y, width, height
** surfaces -> must not be null.
** event_handler -> must not be null.
** on_click -> must not be null.
** parent -> item, ot window where button lies.
** font_data -> font utils struct.
** on_click_info -> data that must be passed to on_click.
*/

typedef struct	s_button t_button;

typedef struct	s_button
{
	int			type;
	bool		is_hovered;
	bool		is_pressed;
	SDL_Rect	properties;
	SDL_Surface *active_surface;
	SDL_Surface	*surface_idle;
	SDL_Surface	*surface_hovered;
	SDL_Surface	*surface_pressed;
	void		(*event_handler)(t_sdl_events *, t_window *, t_button *);
	void		(*on_click)(t_button *);
	void 		*parent;
	t_font_data	font_data;
	void		*on_click_info;
}				t_button;

typedef struct	s_button_info
{
	SDL_Rect	properties;
	SDL_Surface	*surface_idle;
	SDL_Surface	*surface_hovered;
	SDL_Surface	*surface_pressed;
	void		(*event_handler)(t_sdl_events *, t_window *, t_button *);
	void		(*on_click)(t_button *);
	void 		*parent;
	t_font_data	font_data;
	void		*on_click_info;
}				t_button_info;

#endif
