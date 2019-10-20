#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags	flags;
	t_list	*files;

	if (!parse_flags(&flags, argc, argv))
		return (1);
	if (!(files = create_list_from_args(argc, argv)))
		return (1);
	walk(files, &flags);
	return (0);
}