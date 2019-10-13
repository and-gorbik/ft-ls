#include "libft/libft.h"
#include <stdio.h>

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