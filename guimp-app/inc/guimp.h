#ifndef GUIMP_H
# define GUIMP_H

/*
**	INCLUDES
*/

# include "libft.h"
# include "libui.h"
#include <SDL_image.h>

/*
**	DEFINES
*/

# define UNUSED(x) (x == x);
# define WINDOW_AT(i) ((t_window *)vector_get_at(&sdl->windows, i))
# define ITEM_AT(i) ((t_item *)vector_get_at(&window->items, i))
# define BUTTON_AT(i) ((t_button *)vector_get_at(&window->items, i))

/*
**	STRUCTS
*/

typedef struct		s_sdl
{
	t_sdl_events	events;
	t_vector		windows;
}					t_sdl;

/*
**	PROTOTYPES
*/

/*
**	main_loop.c
*/

void				main_loop(t_sdl *sdl);

/*
**	main_loop_events.c
*/

void				main_loop_events(t_sdl *sdl);

/*
**	vector_utilities.c
*/

void				push_back_new_window_to_vector(
						t_vector *vector,
						t_window *window
					);

/*
**	general_utilities.c
*/

void				error(char *reason);

/*
**	initialization_utilities.c
*/

void				initialize_t_sdl(t_sdl *sdl);
void				initialize_sdl();

#endif
