#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
// # include <pwd.h>
// # include <grp.h>
// # include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/acl.h>
// # include <sys/xattr.h>
// # include <limits.h>
// # include <sys/ioctl.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct          s_flags {
	char		        l;
	char		        rr;
	char		        r;
	char		        t;
	char		        a;
}				        t_flags;

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

/*
** mode     - the file permissions
** nlinks   - the number of links
** uid      - the user id
** gid      - the group id
** size     - the file size
** type     - the file type
** time     - the last modification time
** name     - the file name
** path     - the full file path (without file name)
** next     - 
*/

typedef struct          s_file
{
	mode_t			    mode;
	nlink_t			    nlinks;
	uid_t			    uid;
	gid_t			    gid;
	off_t			    size;
	dev_t		        type;
	time_t			    time;
	char			    name[MAXNAMLEN];
	char			    path[PATH_MAX];
	t_list			    *next;
}					    t_file;

/*
** parse flags
*/
int                     parse_flags(t_flags *flags, int argc, char **argv);

/*
** print errors
*/
void                    print_usage(char *src);
void                    print_errno(char *src);

/*
** work with lists
*/
t_list                  *create_list_from_args(int argc, char **argv);
t_list					*create_list_from_dir(char path[PATH_MAX], char *name, t_flags *flags);
int						append_file(t_list **lst, char path[PATH_MAX], char *name);

/*
** helper functions
*/
int                     get_full_path(char path[PATH_MAX], char *name, char full_path[PATH_MAX]);

#endif