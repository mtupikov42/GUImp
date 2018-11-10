#include "guimp.h"

void	render_text_area(t_window *window, t_text_area *area)
{
	SDL_BlitScaled(
			area->active_surface, NULL,
			window->surface, &area->properties
	);
	render_font(window, (t_font_render){
			NULL, &area->font_data, window->surface, area->properties
	});
}

