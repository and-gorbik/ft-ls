#include "ft_ls.h"

// #include "dirent.h"
// #include "sys/stat.h"
// #include <stdlib.h>


// typedef struct		s_file
// {
// 	const char		*name;

// }					t_file;

// t_file	*new_file(const char *name)
// {
// 	t_file	*file;

// 	if (!(file = malloc(sizeof(t_file))))
// 		return (NULL);
// 	file->name = name;
// 	return (file);
// }

// int		cmp_by_name(t_file *one, t_file *two)
// {
// 	return ft_strcmp(one->name, two->name);
// }

// void	del(void *data, size_t size)
// {
// 	if (size != 0)
// 		free(data);
// }

// // сортировка

// // возвращает элемент перед минимумом
// // если минимум - первый элемент, возвращает NULL
// static t_list	*get_before_min(t_list *lst, int (*cmp)(t_file *, t_file *))
// {
// 	t_list	*min;
// 	t_list	*prev;

// 	if (!lst->next)
// 		return (NULL);
	
// 	min = lst;
// 	prev = NULL;
// 	while (lst->next)
// 	{
// 		if (cmp(((t_file *)min->content), ((t_file *)lst->next->content)) > 0)
// 		{
// 			min = lst->next;
// 			prev = lst;
// 		}
// 		lst = lst->next;
// 	}
// 	return prev;
// }

// t_list	*sort_files(t_list *lst, int (*cmp)(t_file *, t_file *))
// {
// 	t_list	*sorted;
// 	t_list	*q;

// 	if (!lst)
// 		return (NULL);
// 	sorted = NULL;
// 	while (lst)
// 	{
// 		if ((q = get_before_min(lst, cmp)))
// 		{
// 			printf("q != NULL\n");
// 			q->next = q->next->next;
// 			q->next->next = sorted;
// 			sorted = q->next;
// 		}
// 		else
// 		{
// 			printf("q == NULL\n");
// 			q = lst;
// 			lst = lst->next;
// 			q->next = sorted;
// 			sorted = q;
// 		}
// 	}
// 	return sorted;
// }


// // чтение списка файлов из директории

// t_list	*ft_readdir(const char *path)
// {
// 	DIR				*dir;
// 	struct dirent	*cur;
// 	t_list			*lst;
// 	t_list			*new;
// 	t_file			*file;

// 	lst = NULL;
// 	if (dir = opendir(path), !dir)
// 		return (NULL);
// 	while ((cur = readdir(dir)))
// 	{
// 		file = new_file(cur->d_name);
// 		if (!(new = ft_lstnew(file, sizeof(t_file))))
// 		{
// 			ft_lstdel(&lst, del);
// 			return (NULL);
// 		}
// 		ft_lstadd(&lst, new);
// 	}
// 	closedir(dir);
// 	return (lst);
// }

void	ft_lstprint(t_list *lst)
{
	// printf("->ft_lstprint\n");
	while (lst)
	{
		printf("%s\n", ((t_file*)lst->content)->name);
		lst = lst->next;
	}
}


void	print_full_path(const char *path, t_flags *flags)
{
	// printf("->print_full_path: %s\n", path);
	if (flags->rr)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
}

t_list	*create_list_from_dir(char path[PATH_MAX], char *name, t_flags *flags)
{
	// printf("->create_list_from_dir: %s %s\n", path, name);
	(void)flags;
	DIR				*d;
	struct dirent	*file;
	t_list			*lst;

	if (d = opendir(path), !d)
	{
		print_errno(name);
		return (NULL);
	}
	lst = NULL;
	while ((file = readdir(d)))
	{
		if (ft_strcmp(file->d_name, ".") && ft_strcmp(file->d_name, ".."))
			if (!append_file(&lst, path, file->d_name))
				print_errno(file->d_name);
	}
	closedir(d);
	return (lst);
}

t_list	*sort_list(t_list *lst, t_flags *flags)
{
	// printf("->sort_list\n");
	(void)flags;
	return (lst);
}

void	delete_list(t_list **lst)
{
	// освободить память!!!
	// printf("->delete_list\n");
	*lst = NULL;
}

void	print_list(t_list *lst, t_flags *flags)
{
	// printf("->print_list\n\n");
	(void)flags;
	while (lst)
	{
		ft_putendl(((t_file *)lst->content)->name);
		lst = lst->next;
	}
}

void	print(t_list *begin, t_flags *flags)
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
				delete_list(&begin);
			}
		}
		cur = cur->next;
	}
}

int		main(int argc, char **argv)
{
	t_flags	flags;
	t_list	*files;

	if (!parse_flags(&flags, argc, argv))
		return (1);
	if (!(files = create_list_from_args(argc, argv)))
		return (1);
	print(files, &flags);
	// delete_files_list(&files);
	return (0);
}