# include "t_window.h"
# include "t_sdl_events.h"
# include "t_button_item.h"

static	void	standart_button_event_mouse_pressed(
			t_sdl_events *events,
			t_window *window,
			t_button *button
		)
{
	SDL_Rect	b_rect;
	int			x;
	int			y;

	if (events->event.window.windowID == window->id)
	{
		b_rect = button->properties;
		SDL_GetMouseState(&x, &y);
		if (x >= b_rect.x && x <= b_rect.x + b_rect.w &&
			y >= b_rect.y && y <= b_rect.y + b_rect.h)
		{
			if (events->event.type == SDL_MOUSEBUTTONDOWN)
				button->active_surface = button->surface_pressed;
			else if (events->event.type == SDL_MOUSEBUTTONUP)
			{
				button->active_surface = button->surface_hovered;
				button->on_click(button->on_click_info);
			}
		}
		else
			button->active_surface = button->surface_idle;
	}
}

static	void	standart_button_event_mouse_motion(
			t_sdl_events *events,
			t_window *window,
			t_button *button
		)
{
	SDL_Rect	b_rect;
	int			x;
	int			y;

	if (events->event.type == SDL_MOUSEMOTION &&
		events->event.window.windowID == window->id)
	{
		b_rect = button->properties;
		SDL_GetMouseState(&x, &y);
		if (x >= b_rect.x && x <= b_rect.x + b_rect.w &&
			y >= b_rect.y && y <= b_rect.y + b_rect.h)
			button->active_surface = button->surface_hovered;
		else
			button->active_surface = button->surface_idle;
	}
}

void	standart_button_event_handler(
			t_sdl_events *events,
			t_button *button
		)
{
	t_window	*window;

	window = button->parent;
	standart_button_event_mouse_pressed(events, window, button);
	standart_button_event_mouse_motion(events, window, button);
}