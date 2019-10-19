#include "ft_ls.h"

static void	print_full_path(const char *path, t_flags *flags)
{
	// printf("->print_full_path: %s\n", path);
	if (flags->rr)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
}

void		walk(t_list *begin, t_flags *flags)
{
	// printf("->print\n");
	t_list	*cur;
	t_file	*file;

	cur = begin;
	while (cur)
	{
		file = (t_file *)cur->content;
		if (S_ISDIR(file->mode))
		{
			print_full_path(file->path, flags);
			begin = create_list_from_dir(file->path, file->name, flags);
			if (begin)
			{
				begin = sort(begin, flags);
				print(begin, flags);
				if (flags->rr)
                    walk(begin, flags);
				// delete_list(&begin);
			}
		}
		cur = cur->next;
	}
}

