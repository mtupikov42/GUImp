#include "guimp.h"

void	render(t_sdl *sdl)
{
	size_t i;

	i = 0;
	while (i < sdl->windows.size)
	{
		if (WINDOW_AT(i)->is_shown)
			render_window(WINDOW_AT(i));
		i += 1;
	}
}

