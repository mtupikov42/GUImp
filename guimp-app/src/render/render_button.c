#include "guimp.h"

void	render_button(t_button *button)
{
	t_window *parent;

	parent = get_parent_window(button);
	SDL_BlitScaled(
			button->active_surface, NULL,
			parent->surface, &button->properties
	);
	render_font(parent, (t_font_render){
		NULL, &button->font_data, parent->surface, button->properties
	});
}
