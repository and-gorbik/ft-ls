#include "ft_ls.h"

char	get_file_type(unsigned short mode)
{
	mode = (mode & S_IFMT);
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISSOCK(mode))
		return ('s');
	if (S_ISFIFO(mode))
		return ('p');
	return ('-');
}

char	*get_permissions(unsigned short st_mode, char *perms)
{
	perms[0] = (S_IRUSR & st_mode) ? 'r' : '-';
	perms[1] = (S_IWUSR & st_mode) ? 'w' : '-';
	perms[2] = (S_IXUSR & st_mode) ? 'x' : '-';
	perms[3] = (S_IRGRP & st_mode) ? 'r' : '-';
	perms[4] = (S_IWGRP & st_mode) ? 'w' : '-';
	perms[5] = (S_IXGRP & st_mode) ? 'x' : '-';
	perms[6] = (S_IROTH & st_mode) ? 'r' : '-';
	perms[7] = (S_IWOTH & st_mode) ? 'w' : '-';
	perms[8] = (S_IXOTH & st_mode) ? 'x' : '-';
	perms[9] = '\0';
	if (S_ISUID & st_mode)
		perms[3] = (perms[3] == '-') ? 'S' : 's';
	if (S_ISGID & st_mode)
		perms[6] = (perms[6] == '-') ? 'S' : 's';
	if (S_ISVTX & st_mode)
		perms[9] = (perms[9] == '-') ? 'T' : 't';
	return perms;
}

void    ft_put_ull_int(unsigned long long n)
{
    if (n >= 10)
		ft_put_ull_int(n / 10);
	ft_putchar((n % 10) + '0');
}

char    *format_time(char *time)
{
    size_t  size;
    char    *ptr;

    size = ft_strlen(time);
    ptr = time + size - 1;
    while (*ptr != ':')
    {
        *ptr = '\0';
        --ptr;
    }
    *ptr = '\0';
    return (time);
}