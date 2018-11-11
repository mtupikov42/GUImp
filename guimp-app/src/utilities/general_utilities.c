#include <dirent.h>
#include "guimp.h"

int		count_elements_in_dir(DIR *dir)
{
	int	ret;

	ret = 0;
	while (readdir(dir))
		ret++;
	return (ret);
}

char 	*get_text_for_rect(char *text, size_t width, size_t font_size)
{
	size_t	text_len;
	size_t	available_text;
	int		available_text_pix;
	int 	i;

	text_len = ft_strlen(text);
	text_len *= font_size / 2;
	available_text_pix = (int)(width - text_len);
	if (available_text_pix < 0)
	{
		available_text = available_text_pix * -1 / font_size * 2;
		text_len = ft_strlen(text) - available_text - 3;
		i = -1;
		while (++i < 3)
		{
			text[text_len] = '.';
			text_len += 1;
		}
		text[text_len] = '\0';
	}
	return (text);
}