/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:29 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 16:46:17 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>

typedef struct		s_tree
{
	char			*name;
	char			*path;
	time_t			sec;
	long			nsec;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_info
{
	char			*name;
	char			*path;
	time_t			sec;
	long			nsec;
}					t_info;

typedef struct		s_ret
{
	int				error;
}					t_ret;

/*
** FT_OPTIONS.C
*/
t_list			*ft_options(char **argv);

/*
** FT_FILES.C
*/
t_tree			*ft_files(char **argv, t_list *options, t_ret *ret);

/*
** FT_TOOLS1.C
*/
int				ft_lstsearch(t_list *options, char c);
size_t			ft_index(char **argv);

/*
** FT_TOOLS2.C
*/
char			*ft_path(char *directory, char *var);
t_tree			*ft_treeinsertAS(t_tree *node, t_info *var);
t_info			*ft_infonew(struct stat buf, char *name, char *directory);

#endif
