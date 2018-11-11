#include "guimp.h"

void	render_button(t_button *button)
{
	t_window *window;

	window = button->parent;
	SDL_BlitScaled(
			button->active_surface, NULL,
			window->surface, &button->properties
	);
	render_font(window, (t_font_render){
		NULL, &button->font_data, window->surface, button->properties
	});
}

