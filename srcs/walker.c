#include "ft_ls.h"

static void	print_full_path(const char *path, t_flags *flags)
{
	if (flags->rr)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
}

static void	walk_dirs(t_list *begin, t_flags *flags)
{
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
                    walk_dirs(begin, flags);
				ft_lstdel(&begin, deleter);
			}
		}
		cur = cur->next;
	}
}

void	walk(t_list *lst, t_flags *flags)
{
	t_list	*dirs;
	t_list	*files;
	t_list	*cur;

	dirs = NULL;
	files = NULL;
	while (lst)
	{
		cur = lst;
		lst = lst->next;
		cur->next = NULL;
		if (S_ISDIR(((t_file *)cur->content)->mode))
			ft_lstappend(&dirs, cur);
		else
			ft_lstappend(&files, cur);
	}
	print(files, flags);
	ft_lstdel(&files, deleter);
	walk_dirs(dirs, flags);
	ft_lstdel(&dirs, deleter);
}

