#include "guimp.h"

void	error(char *reason)
{
	ft_printf("%s\n", reason);
	SDL_Quit();
	exit(2);
}
