#include "guimp.h"

static t_font_render	get_normal_font_setup(t_font_render setup)
{
	setup.font_pos.x += (int)(setup.font_pos.w * 0.05);
	if (!setup.data->size)
		setup.data->size = (size_t)(setup.font_pos.h * 0.7);
	setup.data->text = get_text_for_rect(
			setup.data->text,
			(size_t)(setup.font_pos.w * 0.95),
			setup.data->size
	);
	return (setup);
}

void					reload_font_with_size(t_font *font, size_t new_size)
{
	ft_printf("%s\n", font->name);
	TTF_CloseFont(font->font);
	if (!(font->font = TTF_OpenFont(font->name, (int)new_size)))
		TTF_ERROR
	font->size = new_size;
}

static void				render_font_on_surface(t_font_render setup)
{
	TTF_Font	*font;
	SDL_Surface *text_surface;

	/* if (setup.font->size != setup.data->size) TODO font shit stuff
		reload_font_with_size(setup.font, setup.data->size); */
	if (!(font = TTF_OpenFont(setup.data->name, (int)setup.data->size)))
		TTF_ERROR
	text_surface = TTF_RenderText_Solid(
			font, setup.data->text, setup.data->color
	);
	SDL_BlitSurface(text_surface, NULL, setup.dest_surface, &setup.font_pos);
	SDL_FreeSurface(text_surface);
	TTF_CloseFont(font);
}

void					render_font(t_window *window, t_font_render setup)
{
	t_font *font;
	size_t i;

	UNUSED(window)
	i = 0;
	font = NULL;
	/* while (i < window->fonts->size) TODO font shit stuff
	{
		ft_printf("%d\n", i);
		if (!ft_strcmp(button->font_data.name, FONT_AT(i)->name))
			font = FONT_AT(i);
		i += 1;
	}
	ft_printf("end\n");
	G_ASSERT_TEXT(font == NULL, "no fonts with this name were found."); */
	render_font_on_surface(get_normal_font_setup(setup));
}
