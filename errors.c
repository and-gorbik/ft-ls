#include "ft_ls.h"

void print_usage(char *src)
{
	ft_putstr("ls: illegal option -- ");
	ft_putstr(src);
	ft_putstr("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
}

void print_no_such_file(char *src)
{
	ft_putstr("ls: ");
	ft_putstr(src);
	ft_putstr(": No such file or directory\n");
}