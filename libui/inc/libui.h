#ifndef GUIMP_LIBUI_H
#define GUIMP_LIBUI_H

/*
**	INCLUDES
*/

# include "t_window.h"
# include "t_sdl_events.h"
# include "t_button_item.h"
# include "t_item.h"
# include "e_items.h"
# include "t_font.h"
# include "t_text_area.h"
# include <SDL_image.h>

/*
**	DEFINES
*/

# define UNUSED(x) (x == x);
# define G_ASSERT(b) g_assert(b);
# define G_ASSERT_TEXT(b, t) g_assert_text(b, t);
# define SDL_ERROR error((char *)SDL_GetError());
# define TTF_ERROR error((char *)TTF_GetError());

/*
**	VECTOR_UTILS_DEFINES
*/

# define ITEM_AT(i) ((t_item *)vector_get_at(&window->items, i))
# define WINDOW_AT(i) ((t_window *)vector_get_at(&sdl->windows, i))
# define BUTTON_AT(i) ((t_button *)vector_get_at(&window->items, i))
# define TEXT_AREA_AT(i) ((t_text_area *)vector_get_at(&window->items, i))

# define FONT_AT(i) ((t_font *)vector_get_at(window->fonts, i))

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
**	standart_button_event_handler.c
*/

void		standart_button_event_handler(
				t_sdl_events *events,
				t_window *window,
				t_button *button
			);

/*
**	button.c
*/

t_button	*create_button(t_button_info info);

/*
**	text_area.c
*/

t_text_area	*create_text_area(t_text_area_info info);

/*
**	g_assert.c
*/

void		error(char *reason);
void		g_error(char *reason);
void		g_assert_text(bool check, char *text);
void		g_assert(bool check);

#endif
