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
	window->is_shown = true;
	window->items.size = 0;
	window->items.capacity = 0;
	window->is_main = info.is_main;
	window->id = SDL_GetWindowID(window->window);
	window->surface = SDL_GetWindowSurface(window->window);
	window->event_handler =	!info.event_handler	? &standart_event_handler
												: info.event_handler;
	window->fonts = info.fonts;

	vector_push_back(&window->items, create_button(
			(t_button_info){
					(SDL_Rect){
						0, 300, 100, 70
					},
					NULL, NULL, NULL, NULL,
					&on_click, window,
					(t_font_data) {
						"resources/fonts/BEBAS___.ttf",
						"OH GOD",
						17,
						(SDL_Color) {255, 0, 0, 255}
					}, window
			}
	));

	vector_push_back(&window->items, create_text_area(
			(t_text_area_info){
					(SDL_Rect){
							0, 0, 100, 200
					},
					NULL,
					(t_font_data) {
							"resources/fonts/BEBAS___.ttf",
							"OH GOD",
							18,
							(SDL_Color) {0, 255, 0, 0}
					}
			}
	));

	return (window);
}