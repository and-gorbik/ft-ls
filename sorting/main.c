#include "../libft/libft.h"
#include <stdio.h>

void	del(void *data, size_t size)
{
	if (size != 0)
		free(data);
}

static t_list	*get_before_min(t_list *lst)
{
	t_list	*min;
	t_list	*prev;

	if (!lst->next)
		return (NULL);
	
	min = lst;
	prev = NULL;
	while (lst->next)
	{
		if (((int *)min->content) > ((int *)lst->next->content))
		{
			min = lst->next;
			prev = lst;
		}
		lst = lst->next;
	}
	return prev;
}

t_list	*sort_files(t_list *lst)
{
	t_list	*sorted;
	t_list	*q;

	if (!lst)
		return (NULL);
	sorted = NULL;
	while (lst)
	{
		if ((q = get_before_min(lst)))
		{
			printf("%d", *((int *)q->content));
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

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", *((int*)lst->content));
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*item;

	lst = NULL;
	for (int i = 1; i < argc; ++i)
	{
		int val = atoi(argv[i]);
		item = ft_lstnew(&val, sizeof(int));
		ft_lstappend(&lst, item);
	}
	lst = sort_files(lst);
	ft_lstprint(lst);
	ft_lstdel(&lst, del);
	return (0);
}