#include "guimp.h"

void			free_fonts(t_vector *fonts)
{
	size_t	i;
	t_font	*font;

	i = 0;
	while (i < fonts->size)
	{
		font = vector_get_at(fonts, i);
		ft_strdel(&font->name);
		TTF_CloseFont(font->font);
		free(font);
		i += 1;
	}
}

static bool		is_font(char *name)
{
	char *dot;

	dot = ft_strrchr(name, '.');
	return (ft_strcmp(dot + 1, "ttf") == 0);
}

static char		**read_names_from_dir(char **name_buffer)
{
	DIR				*dir;
	size_t			i;
	struct dirent	*sd;

	i = 0;
	dir = opendir("resources/fonts/");
	while ((sd = readdir(dir)))
		if (is_font(sd->d_name)) {
			name_buffer[i] = ft_strjoin("resources/fonts/", sd->d_name);
			i += 1;
		}
	name_buffer[i] = NULL;
	closedir(dir);
	return (name_buffer);
}

static char		**get_fonts_from_dir()
{
	DIR		*dir;
	int		count_fonts;
	char	**fonts;

	if (!(dir = opendir("resources/fonts/")))
		error("Fonts directory does not exist.");
	count_fonts = count_elements_in_dir(dir);
	closedir(dir);
	G_ASSERT_TEXT(count_fonts == 2, "no fonts were found.")
	fonts = malloc(sizeof(char *) * (count_fonts - 1));
	return (read_names_from_dir(fonts));
}

void			load_fonts_to_vector(t_vector *vector)
{
	char	**fonts;
	t_font	*font;
	size_t 	i;

	i = 0;
	fonts = get_fonts_from_dir();
	while (fonts[i])
	{
		font = malloc(sizeof(t_font));
		font->name = fonts[i];
		font->size = 16;
		ft_printf("%s\n", fonts[i]);
		if (!(font->font = TTF_OpenFont(fonts[i], 16)))
			TTF_ERROR
		vector_push_back(vector, font);
		i += 1;
	}
	free(fonts);
}