#ifndef GUIMP_H
# define GUIMP_H

/*
**	INCLUDES
*/

# include "libft.h"
# include "libui.h"
# include <SDL_image.h>
# include <dirent.h>

/*
**	DEFINES
*/

/*
**	STRUCTS
*/

typedef struct		s_sdl
{
	t_sdl_events	events;
	t_vector		windows;
	t_vector		fonts;
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
**	render.c
*/

void				render(t_sdl *sdl);

/*
**	render_button.c
*/

void				render_button(t_window *window, t_button *button);

/*
**	render_font.c
*/

void				render_font(t_window *window, t_font_render setup);

/*
**	render_window.c
*/

void				render_window(t_window *window);

/*
**	render_text_area.c
*/

void				render_text_area(t_window *window, t_text_area *area);

/*
**	fonts.c
*/

void				load_fonts_to_vector(t_vector *vector);
void				free_fonts(t_vector *fonts);

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

int					count_elements_in_dir(DIR *dir);

/*
**	initialization_utilities.c
*/

void				initialize_t_sdl(t_sdl *sdl);
void				initialize_sdl();

#endif
