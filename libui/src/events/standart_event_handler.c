#include "libui.h"

static void	standart_key_event_handler(t_sdl_events *events, t_window *window)
{
	if (events->event.type == SDL_KEYDOWN &&
		events->event.window.windowID == window->id)
	{
		if (events->event.key.keysym.sym == SDLK_ESCAPE)
		{
			SDL_HideWindow(window->window);
			if (window->is_main)
				events->quit = true;
		}
	}
}

static void	standart_items_event_handler(t_sdl_events *events, t_window *window)
{
	size_t i;
	t_item *item;

	i = 0;
	while (i < window->items.size)
	{
		item = ITEM_AT(i);
		if (item->type == BUTTON)
			BUTTON_AT(i)->event_handler(events, window, BUTTON_AT(i));
		i += 1;
	}
}

static void	standart_window_event_handler(t_sdl_events *events, t_window *window)
{
	if (events->event.type == SDL_WINDOWEVENT &&
		events->event.window.windowID == window->id)
	{
		if (events->event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			SDL_HideWindow(window->window);
			if (window->is_main)
				events->quit = true;
		}
		else if (events->event.window.event == SDL_WINDOWEVENT_HIDDEN)
			window->is_shown = false;
		else if (events->event.window.event == SDL_WINDOWEVENT_SHOWN)
			window->is_shown = true;
		else if (events->event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED
				|| events->event.window.event == SDL_WINDOWEVENT_RESIZED)
			window->surface = SDL_GetWindowSurface(window->window);
	}
}

void	standart_event_handler(t_sdl_events *events, t_window *window)
{
	standart_window_event_handler(events, window);
	standart_key_event_handler(events, window);
	standart_items_event_handler(events, window);
}
