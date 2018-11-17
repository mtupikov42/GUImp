#include "guimp.h"

void	render(t_sdl *sdl)
{
	size_t i;

	i = 0;
	while (i < sdl->windows.size)
	{
		if (WINDOW(i)->is_shown)
			render_window(WINDOW(i));
		i += 1;
	}
}
