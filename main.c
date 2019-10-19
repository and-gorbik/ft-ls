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

// void	ft_lstprint(t_list *lst)
// {
// 	// printf("->ft_lstprint\n");
// 	while (lst)
// 	{
// 		printf("%s\n", ((t_file*)lst->content)->name);
// 		lst = lst->next;
// 	}
// }


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