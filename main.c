#include <stdio.h>
#include "libft/libft.h"
#include "dirent.h"
#include "sys/stat.h"
#include <stdlib.h>


typedef struct		s_file
{
	const char		*name;

}					t_file;

t_file	*new_file(const char *name)
{
	t_file	*file;

	if (!(file = malloc(sizeof(t_file))))
		return (NULL);
	file->name = name;
	return (file);
}

int		cmp_by_name(t_file *one, t_file *two)
{
	return ft_strcmp(one->name, two->name);
}

void	del(void *data, size_t size)
{
	if (size != 0)
		free(data);
}

// сортировка

// возвращает элемент перед минимумом
// если минимум - первый элемент, возвращает NULL
static t_list	*get_before_min(t_list *lst, int (*cmp)(t_file *, t_file *))
{
	t_list	*min;
	t_list	*prev;

	if (!lst->next)
		return (NULL);
	
	min = lst;
	prev = NULL;
	while (lst->next)
	{
		if (cmp(((t_file *)min->content), ((t_file *)lst->next->content)) > 0)
		{
			min = lst->next;
			prev = lst;
		}
		lst = lst->next;
	}
	return prev;
}

t_list	*sort_files(t_list *lst, int (*cmp)(t_file *, t_file *))
{
	t_list	*sorted;
	t_list	*q;

	if (!lst)
		return (NULL);
	sorted = NULL;
	while (lst)
	{
		if ((q = get_before_min(lst, cmp)))
		{
			printf("q != NULL\n");
			q->next = q->next->next;
			q->next->next = sorted;
			sorted = q->next;
		}
		else
		{
			printf("q == NULL\n");
			q = lst;
			lst = lst->next;
			q->next = sorted;
			sorted = q;
		}
	}
	return sorted;
}


// чтение списка файлов из директории

t_list	*ft_readdir(const char *path)
{
	DIR				*dir;
	struct dirent	*cur;
	t_list			*lst;
	t_list			*new;
	t_file			*file;

	lst = NULL;
	if (dir = opendir(path), !dir)
		return (NULL);
	while ((cur = readdir(dir)))
	{
		file = new_file(cur->d_name);
		if (!(new = ft_lstnew(file, sizeof(t_file))))
		{
			ft_lstdel(&lst, del);
			return (NULL);
		}
		ft_lstadd(&lst, new);
	}
	closedir(dir);
	return (lst);
}

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", ((t_file*)lst->content)->name);
		lst = lst->next;
	}
}

int		main(int argc, char **argv) {
	t_list	*lst;

	if (argc != 2) {
		printf("Usage: ./a.out dirname\n");
		return (1);
	}
	if (!(lst = ft_readdir(argv[1])))
	{
		printf("Error with reading a directory\n");
		return (1);
	}
	lst = sort_files(lst, cmp_by_name);
	ft_lstprint(lst);
	ft_lstdel(&lst, del);
	return (0);
}

/*

int     cmp(const t_list *one, const t_list *two)
{
    return (*((int *)one->content) < *((int *)two->content));
}

void    del(void *data, size_t size)
{
    if (size != 0)
        free(data);
}

t_list  *before_min(t_list *lst, int cmp(const t_list *, const t_list *))
{
    t_list  *min;
    t_list  *prev;

    if (!lst->next)
        return (NULL);
    prev = NULL;
    min = lst;
    while (lst->next)
    {
        if (cmp(lst->next, min))
        {
            min = lst->next;
            prev = lst;
        }
        lst = lst->next;
    }
    return (prev);
}

t_list  *sort(t_list *lst, int cmp(const t_list *, const t_list *))
{
    t_list  *sorted;
    t_list  *prev;
    t_list  *next;

    sorted = NULL;
    while (lst)
    {
        prev = before_min(lst, cmp);
        if (!prev)
        {
            next = lst->next;
            lst->next = NULL;
            ft_lstappend(&sorted, lst);
            lst = next;
        }
        else
        {
            next = prev->next->next;
            prev->next->next = NULL;
            ft_lstappend(&sorted, prev->next);
            prev->next = next;
        }
    }
    return (sorted);
}

void    lstprint(t_list *lst)
{
    while (lst)
    {
        printf("%d ", *((int *)lst->content));
        lst = lst->next;
    }
    printf("\n");
}

int     main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: ./a.out [list_item1, list_item2, ...]\n");
        return (1);
    }

    // creating a new unordered list
    t_list  *lst = NULL;
    for (int i = 1; i < argc; ++i)
    {
        int     val = ft_atoi(argv[i]);
        t_list  *item = ft_lstnew(&val, sizeof(int));
        ft_lstadd(&lst, item);
    }
    lstprint(lst);
    lst = sort(lst, cmp);
    lstprint(lst);
    ft_lstdel(&lst, del);
    return (0);
}
*/
