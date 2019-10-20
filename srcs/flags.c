#include "ft_ls.h"

static int  set_flags(t_flags *flags, char *src)
{
	// printf("->set_flags\n");
	while (*(++src)) {
		switch (*src) {
		case 'l':
			flags->l = 1;
			break;
		case 'R':
			flags->rr = 1;
			break;
		case 'r':
			flags->r = 1;
			break;
		case 't':
			flags->t = 1;
			break;
		case 'a':
			flags->a = 1;
			break;
		default:
            print_usage(src);
			return (0);	
		}
	}
	return (1);
}

int         parse_flags(t_flags *flags, int argc, char **argv)
{
	// printf("->parse_flags\n");
	int		i;

	i = 0;
	while (++i < argc && argv[i][0] == '-' && argv[i][1])
	{
		if (!set_flags(flags, argv[i]))
            return (0);
	}
	// printf("a: %d\n", flags->a);
	// printf("l: %d\n", flags->l);
	// printf("r: %d\n", flags->r);
	// printf("R: %d\n", flags->rr);
	// printf("t: %d\n", flags->t);

	return (1);
}