#include <t_item.h>
#include "guimp.h"

void	main_loop(t_sdl *sdl)
{
	while (!sdl->events.quit)
	{
		while (SDL_PollEvent(&sdl->events.event))
			main_loop_events(sdl);
		render(sdl);
	}
}
