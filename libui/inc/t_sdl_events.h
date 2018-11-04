#ifndef GUIMP_T_SDL_EVENTS_H
# define GUIMP_T_SDL_EVENTS_H

#include <SDL_events.h>
# include "stdbool.h"

typedef struct	s_sdl_events
{
	bool		quit;
	SDL_Event	event;
}				t_sdl_events;

#endif
