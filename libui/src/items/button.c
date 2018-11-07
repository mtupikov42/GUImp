#include <ft_printf.h>
#include "libui.h"

t_button *create_button(t_button_info info)
{
	G_ASSERT_TEXT(info.parent, NULL, "parent cannot be null.")
	G_ASSERT_TEXT(info.on_click, NULL, "on_click cannot be null.")
	t_button *button = malloc(sizeof(t_button));
	button->is_hovered = false;
	button->is_pressed = false;
	button->type = BUTTON;
	button->properties = info.properties;
	button->surface_idle = info.surface_idle ? info.surface_idle : NULL;
	button->surface_hovered = info.surface_hovered ? info.surface_hovered : NULL;
	button->surface_pressed = info.surface_pressed ? info.surface_pressed : NULL;
	button->parent = info.parent;
	button->event_handler = info.event_handler; // TODO standart event_handler
	button->on_click = info.on_click;
	return (button);
}
