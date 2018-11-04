#include "t_sdl_events.h"
#include "t_window.h"

void	standart_key_event_handler(t_sdl_events *events, t_window *window)
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

void	standart_window_event_handler(t_sdl_events *events, t_window *window)
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
	}
}

void	standart_event_handler(t_sdl_events *events, t_window *window)
{
	standart_window_event_handler(events, window);
	standart_key_event_handler(events, window);
}
