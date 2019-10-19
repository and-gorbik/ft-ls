#include "ft_ls.h"

static void print_full_path(const char *path, t_flags *flags)
{
	// printf("->print_full_path: %s\n", path);
	if (flags->rr)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
}

static void print_list(t_list *lst, t_flags *flags)
{
	// printf("->print_list\n\n");
	(void)flags;
	while (lst)
	{
		ft_putendl(((t_file *)lst->content)->name);
		lst = lst->next;
	}
}

void        print(t_list *begin, t_flags *flags)
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
			// display full path where it's needed
			print_full_path(file->path, flags);
			begin = create_list_from_dir(file->path, file->name, flags);
			if (begin)
			{
				begin = sort_list(begin, flags);
				print_list(begin, flags);
				if (flags->rr)
					print(begin, flags);
				// delete_list(&begin);
			}
		}
		cur = cur->next;
	}
}

