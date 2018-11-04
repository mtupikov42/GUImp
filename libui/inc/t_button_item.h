#ifndef GUIMP_T_BUTTON_ITEM_H
# define GUIMP_T_BUTTON_ITEM_H

/*
**	INCLUDES
*/

# include <SDL.h>
# include <stdbool.h>
# include "e_items.h"

/*
**	STRUCTS
*/

/*
** t_button
** properties -> SDL struct with x, y, width, height
*/

typedef struct	s_button
{
	int			type;
	bool		is_hovered;
	bool		is_pressed;
	SDL_Rect	properties;
	SDL_Surface	*surface_idle;
	SDL_Surface	*surface_hovered;
	SDL_Surface	*surface_pressed;
}				t_button;

typedef struct	s_button_info
{
	SDL_Rect	properties;
	SDL_Surface	*surface_idle;
	SDL_Surface	*surface_hovered;
	SDL_Surface	*surface_pressed;
}				t_button_info;

#endif
