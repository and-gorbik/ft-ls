#include "ft_ls.h"

void	print_usage(char *src)
{
	// printf("->print_usage\n");
	ft_putstr_fd("ft_ls: illegal option -- ", STDERR_FILENO);
	ft_putstr_fd(src, STDERR_FILENO);
	ft_putendl_fd("\nusage: ft_ls [-alRrt] [file ...]", STDERR_FILENO);
}

void	print_errno(char *src)
{
	// printf("->print_errno\n");
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	ft_putstr_fd(src, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), 2);
}