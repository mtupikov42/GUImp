#include "guimp.h"

int		main(int argc, char **argv)
{
	t_sdl sdl;

	UNUSED(argc)
	UNUSED(argv)
	initialize_sdl();
	initialize_t_sdl(&sdl);

	push_back_new_window_to_vector(&sdl.windows, create_empty_window(
			(t_window_info) {
					"Check 1", true, 100, 900, SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOW_RESIZABLE, NULL
			}));

	push_back_new_window_to_vector(&sdl.windows, create_empty_window(
			(t_window_info) {
					"Check 2", false, 900, 100, SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOW_RESIZABLE, NULL
			}));

	main_loop(&sdl);
	IMG_Quit();
	SDL_Quit();
	return (0);
}