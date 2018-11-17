#include "guimp.h"

void	render_window(t_window *parent)
{
	size_t i;
	t_item *item;

	SDL_FillRect(parent->surface, NULL, 0x000000);
	i = 0;
	while (i < parent->items.size)
	{
		item = ITEM_AT(i);
		if (item->type == BUTTON)
			render_button(BUTTON_AT(i));
		else if (item->type == TEXT_AREA)
			render_text_area(TEXT_AREA_AT(i));
		else if (item->type == WINDOW && WINDOW_AT(i)->is_shown)
			render_window(WINDOW_AT(i));
		i += 1;
	}
	SDL_UpdateWindowSurface(parent->window);
}
