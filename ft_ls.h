/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:29 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/03 12:11:09 by jle-quel         ###   ########.fr       */
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

# define SEC buf.st_mtimespec.tv_sec
# define NSEC buf.st_mtimespec.tv_nsec

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
}					t_info;

typedef struct		s_ret
{
	int				error;
}					t_ret;

/*
** INITIALIZE TREES (MAIN)
*/
t_list			*ft_options(char **argv);
t_tree			*ft_files(char **argv, t_list *options, t_ret *ret, t_tree *node);
t_tree			*ft_directories(char **argv, t_list *options, t_tree *node);

/*
** TOOLS
*/
int				ft_lstsearch(t_list *options, char c);
size_t			ft_index(char **argv);
void			ft_error(t_ret *ret, char *str);
char			*ft_path(char *directory, char *var);
void			ft_treeclr(t_tree *node);
void			ft_info(t_info *var, char *name, char *directory);
t_tree			*ft_treeinsertAS(t_tree *node, t_info var, time_t sec, long nsec);
t_tree			*ft_treeinsertTI(t_tree *node, t_info var, time_t sec, long nsec);

/*
** PRINTING
*/
void 			ft_printOR(t_tree *files, int flag);
void 			ft_printIN(t_tree *files, int flag);
void 			ft_printfiles(t_tree *files, t_list *options);
void			ft_printlong(char *str, char *path);

#endif
