#include "ft_ls.h"

static t_list   *before_min(t_list *lst, int cmp(const t_list *, const t_list *))
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

t_list          *sort_list(t_list *lst, t_flags *flags)
{
    t_list  *sorted;
    t_list  *prev;
    t_list  *next;
    t_cmp   cmp;

    cmp = cmp_by_flag(flags);
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