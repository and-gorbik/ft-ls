#include "ft_ls.h"

static int  cmp_by_alpha_asc(const t_list *one, const t_list *two)
{
    return ft_strcmp(((t_file *)one->content)->name, ((t_file *)two->content)->name) <= 0;
}

static int  cmp_by_alpha_desc(const t_list *one, const t_list *two)
{
    return ft_strcmp(((t_file *)one->content)->name, ((t_file *)two->content)->name) >= 0;
}

static int  cmp_by_time_asc(const t_list *one, const t_list *two)
{
    (void)one;
    (void)two;
    return (1);
}

static int  cmp_by_time_desc(const t_list *one, const t_list *two)
{
    (void)one;
    (void)two;
    return (1);
}

t_cmp       cmp_by_flag(t_flags *flags)
{
    if (flags->t)
        return (flags->r ? cmp_by_time_desc : cmp_by_time_asc);
    return (flags->r ? cmp_by_alpha_desc : cmp_by_alpha_asc);
}