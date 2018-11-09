#include <ft_printf.h>
#include "libui.h"

t_button *create_button(t_button_info info)
{
	G_ASSERT_TEXT(info.parent, NULL, "button parent cannot be null.")
	G_ASSERT_TEXT(info.on_click, NULL, "button on_click func cannot be null.")
	G_ASSERT_TEXT(info.font_data.text, NULL, "button text cannot be null.")
	G_ASSERT_TEXT(info.on_click_info, NULL, "btn on_click data cannot be null.")
	G_ASSERT_TEXT(info.font_data.name, NULL, "button must have font to show text.")
	t_button *button = malloc(sizeof(t_button));
	button->is_hovered = false;
	button->is_pressed = false;
	button->type = BUTTON;
	button->properties = info.properties;
	button->surface_idle = info.surface_idle	? info.surface_idle
												: LOAD_STD_BTN_IDLE;
	button->surface_hovered = info.surface_hovered	? info.surface_hovered
													: LOAD_STD_BTN_HOV;
	button->surface_pressed = info.surface_pressed	? info.surface_pressed
													: LOAD_STD_BTN_PRS;
	button->active_surface = button->surface_idle;
	button->parent = info.parent;
	button->event_handler = !info.event_handler ? &standart_button_event_handler
												: info.event_handler;
	button->on_click = info.on_click;
	button->font_data = info.font_data;
	return (button);
}
