#include <dirent.h>

int		count_elements_in_dir(DIR *dir)
{
	int	ret;

	ret = 0;
	while (readdir(dir))
		ret++;
	return (ret);
}