#include <SDL.h>
#include "ft_printf.h"

void	g_error(char *reason)
{
	ft_printf("G_ASSERT ERROR: %s\n", reason);
	SDL_Quit();
	exit(2);
}

void	g_assert_text(void *value1, void *value2, char *text)
{
	if (value1 == value2)
		g_error(text);
}

void	g_assert(void *value1, void *value2)
{
	g_assert_text(value1, value2, "values are not equal.");
}
