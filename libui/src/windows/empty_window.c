#include "libui.h"

void	on_click(t_button *b)
{
	UNUSED(b)
	ft_printf("click");
}

t_window *create_empty_window(t_window_info info)
{
	t_window *window;

	G_ASSERT_TEXT(info.fonts == NULL, "fonts vector must not be null.")
	if (!(window = malloc(sizeof(t_window))))
		return NULL;
	window->window = SDL_CreateWindow(
						info.title, info.x, info.y,
						info.width, info.height, info.flags
					);
	if (!window->window)
		return NULL;
	window->type = WINDOW;
	window->is_shown = info.is_shown;
	window->items.size = 0;
	window->items.capacity = 0;
	window->is_main = info.is_main;
	window->id = SDL_GetWindowID(window->window);
	window->surface = SDL_GetWindowSurface(window->window);
	window->event_handler =	!info.event_handler	? &standart_event_handler
												: info.event_handler;
	window->fonts = info.fonts;
	window->parent = info.parent;
	window->is_active = true;

	vector_push_back(&window->items, create_button(
			(t_button_info){
					(SDL_Rect){
						0, 300, 500, 30
					}, NULL, NULL, NULL, NULL,
					&on_click, window,
					(t_font_data) {
						"resources/fonts/BEBAS___.ttf",
						ft_strdup("You are ready to review your patronage"),
						0,
						(SDL_Color) {255, 0, 0, 255}
					}, window
			}
	));

	vector_push_back(&window->items, create_text_area(
			(t_text_area_info){
					(SDL_Rect){
							0, 0, 400, 70
					}, NULL,
					(t_font_data) {
							"resources/fonts/BEBAS___.ttf",
							ft_strdup("You are ready to review your patronage"),
							0,
							(SDL_Color) {0, 255, 0, 0}
					}, window
			}
	));

	return (window);
}
