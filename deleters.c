#include "ft_ls.h"

void    deleter(void *content, size_t size)
{
    if (size > 0)
        free(content);
}