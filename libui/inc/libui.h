#ifndef GUIMP_LIBUI_H
#define GUIMP_LIBUI_H

/*
**	INCLUDES
*/

# include "t_window.h"
# include "t_sdl_events.h"
# include "t_button_item.h"
# include "e_items.h"
# include <SDL_image.h>

/*
**	PROTOTYPES
*/

t_window	*create_empty_window(t_window_info info);

void		standart_event_handler(t_sdl_events *events, t_window *window);

t_button	*create_button(t_button_info info);

#endif
