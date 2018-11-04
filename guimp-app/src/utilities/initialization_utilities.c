#include <SDL_image.h>
#include "guimp.h"

void	initialize_t_sdl(t_sdl *sdl)
{
	sdl->events.quit = false;
	sdl->windows.size = 0;
	sdl->windows.capacity = 0;
}

void	initialize_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error((char *)SDL_GetError());
	if (IMG_Init(IMG_INIT_PNG) < 0)
		error((char *)SDL_GetError());
}