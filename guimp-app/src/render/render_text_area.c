#include "guimp.h"

void	render_text_area(t_text_area *area)
{
	t_window *parent;

	parent = get_parent_window(area);
	SDL_BlitScaled(
			area->active_surface, NULL,
			parent->surface, &area->properties
	);
	render_font(parent, (t_font_render){
			NULL, &area->font_data, parent->surface, area->properties
	});
}

