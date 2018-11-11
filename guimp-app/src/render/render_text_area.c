#include "guimp.h"

void	render_text_area(t_text_area *area)
{
	t_window *window;

	window = area->parent;
	SDL_BlitScaled(
			area->active_surface, NULL,
			window->surface, &area->properties
	);
	render_font(window, (t_font_render){
			NULL, &area->font_data, window->surface, area->properties
	});
}

