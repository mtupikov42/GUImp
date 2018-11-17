#include "guimp.h"

static void	*get_parent(void *parent) // TODO window search with recursion
{
	t_item *item;

	item = parent;
	if (item->type == MENU)
		return (NULL);
	G_ASSERT_TEXT(true, "Can't find parent window.")
	return (NULL);
}

t_window	*get_parent_window(void *item)
{
	t_item *parent;
	t_item *current_item;
	t_window *parent_window;

	current_item = item;
	parent = current_item->parent;
	parent_window = parent->type != WINDOW	? get_parent(parent)
									 		: parent;
	return (parent_window);
}