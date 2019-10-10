#ifndef WALKER_H
# define WALKER_H

#include "libft/libft.h"
#include "dirent.h"
//#include "sys/stat.h"

typedef struct	s_stack
{
	t_list		*top;
}				t_stack;

void push(t_stack *stack, struct stat *stat);
struct stat pop(t_stack *stack);

void walk(const char *root);

#endif