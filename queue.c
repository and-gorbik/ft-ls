#include "ft_ls.h"

static void		del(void *data, size_t size)
{
	if (size != 0)
		free(data);
}

t_list			*append(t_queue *q, const char *path)
{
	t_list	*item;
	size_t	size;

	size = ft_strlen(path);
	if (!(item = ft_lstnew(path, size + 1)))
		return (NULL);

	return (item);
}

t_list			*pop(t_queue *q)
{

}

void			free_all(t_queue *q)
{

}