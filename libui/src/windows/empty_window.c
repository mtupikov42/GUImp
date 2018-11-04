#include "libui.h"

t_window *create_empty_window(t_window_info info)
{
	t_window *window;

	if (!(window = malloc(sizeof(t_window))))
		return NULL;
	window->window = SDL_CreateWindow(
						info.title, info.x, info.y,
						info.width, info.height, info.flags
					);
	if (!window->window)
		return NULL;
	window->is_shown = true;
	window->items.size = 0;
	window->items.capacity = 0;
	window->is_main = info.is_main;
	window->id = SDL_GetWindowID(window->window);
	window->surface = SDL_GetWindowSurface(window->window);
	window->event_handler =	!info.event_handler	? &standart_event_handler
												: info.event_handler;
	return (window);
}