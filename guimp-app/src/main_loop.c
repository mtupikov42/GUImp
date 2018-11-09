#include <t_item.h>
#include "guimp.h"

void	reload_font_with_size(t_font *font, size_t new_size)
{
	TTF_CloseFont(font->font);
	TTF_OpenFont(font->name, (int)new_size);
	font->size = new_size;
}

void	render_font_on_surface(t_font_render setup)
{
	SDL_Surface *text_surface;

	if (setup.font->size != setup.data.size)
		reload_font_with_size(setup.font, setup.data.size); // TODO font path might be not valid
	text_surface = TTF_RenderText_Solid(setup.font->font, setup.data.text, setup.data.color);
	SDL_BlitSurface(text_surface, NULL, setup.dest_surface, &setup.font_pos);
	SDL_FreeSurface(text_surface);
}

void	render_font(t_window *window, t_button *button)
{
	t_font *font;
	size_t i;

	i = 0;
	font = NULL;
	while (i < window->fonts->size)
	{
		if (!ft_strcmp(button->font_data.name, FONT_AT(i)->name))
			font = FONT_AT(i);
		i += 1;
	}
	G_ASSERT_TEXT(font, NULL, "no fonts with this name were found.");
	render_font_on_surface((t_font_render){
		font, button->font_data, window->surface,
		(SDL_Rect){ // TODO better font position handling
			button->properties.x + 30,
			button->properties.y,
			20,
			20
		}
	});
}

void	render_button(t_window *window, t_button *button)
{
	SDL_BlitScaled(
			button->active_surface, NULL,
			window->surface, &button->properties
	);
	render_font(window, button);
}

void	render_window(t_window *window)
{
	size_t i;
	t_item *item;

	i = 0;
	while (i < window->items.size)
	{
		item = ITEM_AT(i);
		if (item->type == BUTTON)
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