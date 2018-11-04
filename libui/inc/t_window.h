#ifndef GUIMP_T_WINDOW_H
# define GUIMP_T_WINDOW_H

/*
**	INCLUDES
*/

# include <SDL.h>
# include "libft.h"
# include "stdbool.h"
# include "t_sdl_events.h"

/*
**	STRUCTS
*/

/*
** t_window
** is_main -> if true, then when we close window application shuts down.
** id -> identifier of window.
** event_handler -> function in which events of this window are handled.
*/

typedef struct  	s_window t_window;

struct				s_window
{
	bool			is_main;
	bool			is_shown;
	Uint32 			id;
	void			(*event_handler)(t_sdl_events *, t_window *);
	t_vector		items;
	SDL_Window		*window;
	SDL_Surface		*surface;
};

/*
** t_window
** title -> title of window.
** is_main -> as above.
** width, height -> obviously.
** x, y -> starting positions of window.
** flags -> flags such as 'resizable', 'shown', etc.
** event_handler -> as above.
*/

typedef struct		s_window_info
{
	char			*title;
	bool			is_main;
	int 			width;
	int 			height;
	int 			x;
	int 			y;
	Uint32 			flags;
	void			(*event_handler)(t_sdl_events *, t_window *);
}					t_window_info;

#endif
