#include <t_text_area.h>
#include "libui.h"

t_text_area	*create_text_area(t_text_area_info info)
{
	t_text_area *area;

	G_ASSERT_TEXT(info.parent == NULL, "parent can't be null.")
	area = malloc(sizeof(t_text_area));
	area->type = TEXT_AREA;
	area->active_surface = info.active_surface	? info.active_surface
												: LOAD_STD_TA_IDLE;
	area->font_data = info.font_data;
	area->properties = info.properties;
	area->parent = info.parent;
	return (area);
}
