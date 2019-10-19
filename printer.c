#include "ft_ls.h"

static void print_files(t_list *lst, t_flags *flags)
{
    char    *name;

	while (lst)
	{
        name = ((t_file *)lst->content)->name;
        if (flags->a || name[0] != '.')
            ft_putendl(name);
		lst = lst->next;
	}
}

static void print_files_detailed(t_list *lst, t_flags *flags)
{
    t_file  *file;
    char    perms[10];

    while (lst)
    {
        file = (t_file *)lst->content;
        if (flags->a || file->name[0] != '.')
        {
            ft_putchar(get_file_type(file->mode));
            ft_putstr(get_permissions(file->mode, perms));
            ft_putchar(' ');
            ft_putnbr(file->nlinks);
            ft_putchar('\t');
            ft_putstr(getpwuid(file->uid)->pw_name);
            ft_putchar(' ');
            ft_putstr(getgrgid(file->gid)->gr_name);
            ft_putchar(' ');
            ft_put_ull_int(file->size);
            ft_putchar('\t');
            ft_putstr(format_time(ctime(&file->time)));
            ft_putchar(' ');
            ft_putendl(file->name);
        }
        lst = lst->next;
    }
}

void        print(t_list *lst, t_flags *flags)
{
    if (flags->l)
        print_files_detailed(lst, flags);
    else
        print_files(lst, flags);
}