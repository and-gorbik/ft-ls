#include "ft_ls.h"

static int      set_full_path(char full_path[PATH_MAX], char path[PATH_MAX], const char *name)
{
	int	len;

	len = ft_strlen(path);
	if (len + 1 + ft_strlen(name) >= PATH_MAX)
	{
		errno = ENAMETOOLONG;
		return (0);
	}
	if (!len)
	{
		ft_strcpy(full_path, name);
		return (1);
	}
	ft_strcpy(full_path, path);
	ft_strcpy(full_path + len, "/");
	ft_strcpy(full_path + len + 1, name);
	return (1);
}

static t_list   *new_file(char path[PATH_MAX], const char *name, const t_stat *stat)
{
    t_list  *new;
	t_file	*file;

    if (!(new = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(file = ft_memalloc(sizeof(t_file))))
	{
		free(new);
		return (NULL);
	}
	ft_strcpy(file->name, name);
	set_full_path(file->path, path, name);
	file->uid = stat->st_uid;
	file->gid = stat->st_gid;
	file->mode = stat->st_mode;
	file->nlinks = stat->st_nlink;
	file->size = stat->st_size;
	file->type = stat->st_rdev;
	file->time = stat->st_mtimespec.tv_sec;
	file->next = NULL;
	new->content = file;
	new->content_size = sizeof(t_file);
	new->next = NULL;
	return (new);
}

static int		append_file(t_list **lst, char path[PATH_MAX], char *name)
{
	char	full_path[PATH_MAX];
	t_stat	stat;
	t_list	*cur;

	if (!(set_full_path(full_path, path, name)))
		return (0);
	if (lstat(full_path, &stat) == -1)
		return (0);
	if (!(cur = new_file(path, name, &stat)))
		return (0);
	ft_lstappend(lst, cur);
	return (1);
}

t_list          *create_files_list(int argc, char **argv)
{
	t_list	*begin;
	int		i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1])
        ++i;
	begin = NULL;
	if (argc == 1)
		append_file(&begin, "", ".");
	// sort strings - потому что ошибки выводятся в алфавитном порядке
    while (i < argc)
    {
		if (!(append_file(&begin, "", argv[i])))
			print_no_such_file(argv[i]);
		++i;
    }
	return (begin);
}

// void			delete_files_list(t_list **lst)
// {
// 	t_list	*cur;

// 	cur = *lst;
// 	while (cur)
// 	{
// 		cur = cur->next;
// 		ft_lstdel
// 	}
// }