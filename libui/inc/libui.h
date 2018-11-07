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
**	DEFINES
*/

# define G_ASSERT(v1, v2) g_assert(v1, v2);
# define G_ASSERT_TEXT(v1, v2, v3) g_assert_text(v1, v2, v3);

/*
**	PROTOTYPES
*/

/*
**	empty_window.c
*/

t_window	*create_empty_window(t_window_info info);

/*
**	standart_event_handler.c
*/

void		standart_event_handler(t_sdl_events *events, t_window *window);

/*
**	button.c
*/

t_button	*create_button(t_button_info info);

/*
**	g_assert.c
*/

void		g_error(char *reason);
void		g_assert_text(void *value1, void *value2, char *text);
void		g_assert(void *value1, void *value2);

#endif
