#include "guimp.h"

void	push_back_new_window_to_vector(t_vector *vector, t_window *window)
{
	if (!window)
		error((char *)SDL_GetError());
	vector_push_back(vector, window);
}
