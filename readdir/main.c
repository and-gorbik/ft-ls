#include <stdio.h>
#include "../libft/libft.h"
#include "dirent.h"

int		ft_readdir(const char *path)
{
	DIR				*d;
	struct dirent	*cur;

	if (d = opendir(path), !d)
		return (-1);
	while ((cur = readdir(d)))
	{
		if (ft_strcmp(cur->d_name, ".") && ft_strcmp(cur->d_name, ".."))
		{
			printf("%s\n", cur->d_name);
		}
	}
	closedir(d);
	return (0);
}

int		main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: ./a.out dirname\n");
		return (1);
	}
	if (ft_readdir(argv[1]) == -1)
	{
		printf("This path is not a directory\n");
		return (1);
	}
	return (0);
}