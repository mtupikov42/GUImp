#include "guimp.h"

void	render_window(t_window *window)
{
	size_t i;
	t_item *item;

	SDL_FillRect(window->surface, NULL, 0x000000);
	i = 0;
	while (i < window->items.size)
	{
		item = ITEM_AT(i);
		if (item->type == BUTTON)
			render_button(BUTTON_AT(i));
		else if (item->type == TEXT_AREA)
			render_text_area(TEXT_AREA_AT(i));
		i += 1;
	}
	SDL_UpdateWindowSurface(window->window);
}
