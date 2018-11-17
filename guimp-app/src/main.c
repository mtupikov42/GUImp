#include "guimp.h"

int		main(int argc, char **argv)
{
	t_sdl sdl;

	UNUSED(argc)
	UNUSED(argv)
	initialize_sdl();
	initialize_t_sdl(&sdl);

	//load_fonts_to_vector(&sdl.fonts); TODO fucking strange font thing

	t_window *w = create_empty_window(
			(t_window_info) {
					"GUImp", true, true, 500, 800, SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOW_RESIZABLE, NULL,
					&sdl.fonts, NULL
			});

	push_back_new_window_to_vector(&sdl.windows, w);

	push_back_new_window_to_vector(&w->items, create_empty_window(
			(t_window_info) {
					"GUImp", false, true, 500, 800, 0, 0, SDL_WINDOW_SHOWN, NULL,
					&sdl.fonts, NULL
			}));

	main_loop(&sdl);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	//system("leaks guimp");
	return (0);
}
