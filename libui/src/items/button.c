#include <ft_printf.h>
#include "t_button_item.h"
#include "e_items.h"

t_button *create_button(t_button_info info)
{
	t_button *button = malloc(sizeof(t_button));
	button->is_hovered = false;
	button->is_pressed = false;
	button->type = BUTTON;
	button->properties = info.properties;
	button->surface_idle = info.surface_idle ? info.surface_idle : NULL;
	button->surface_hovered = info.surface_hovered ? info.surface_hovered : NULL;
	button->surface_pressed = info.surface_pressed ? info.surface_pressed : NULL;
	return (button);
}
