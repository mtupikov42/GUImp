#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "ft_printf.h"
#include "stdbool.h"

void	error(char *reason)
{
	ft_printf("%s\n", reason);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	exit(2);
}

void	g_error(char *reason)
{
	ft_printf("G_ASSERT ERROR: %s\n", reason);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	exit(2);
}

void	g_assert_text(bool check, char *text)
{
	if (check)
		g_error(text);
}

void	g_assert(bool check)
{
	g_assert_text(check, "values are not equal.");
}
