#include <t_item.h>
#include "guimp.h"

void	render_button(t_window *window, t_button *button)
{
	if (button->is_pressed)
		SDL_BlitScaled(
				button->surface_pressed, NULL,
				window->surface, &button->properties
		);
	else if (button->is_hovered)
		SDL_BlitScaled(
				button->surface_hovered, NULL,
				window->surface, &button->properties
		);
	else
		SDL_BlitScaled(
				button->surface_idle, NULL,
				window->surface, &button->properties
		);
}

void	render_window(t_window *window)
{
	size_t i;

	i = 0;
	while (i < window->items.size)
	{
		if (ITEM_AT(i)->type == BUTTON)
			render_button(window, BUTTON_AT(i));
		i += 1;
	}
	SDL_UpdateWindowSurface(window->window);
}

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

void	main_loop(t_sdl *sdl)
{
	while (!sdl->events.quit)
	{
		while (SDL_PollEvent(&sdl->events.event))
			main_loop_events(sdl);
		render(sdl);
	}
}