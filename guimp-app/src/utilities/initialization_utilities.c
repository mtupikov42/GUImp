#include <SDL_image.h>
#include <SDL_ttf.h>
#include "guimp.h"

void	initialize_t_sdl(t_sdl *sdl)
{
	sdl->events.quit = false;
	sdl->windows.size = 0;
	sdl->windows.capacity = 0;
}

void	initialize_sdl()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ||
		IMG_Init(IMG_INIT_PNG) < 0 ||
		TTF_Init() < 0)
		SDL_ERROR
}