/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:55:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/03 10:28:32 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_tree	*ft_sortTI(char **argv, t_ret *ret, t_tree *node)
{
	size_t			index;
	DIR				*dirp;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (!(dirp = opendir(argv[index])))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertTI(node, var, SEC, NSEC)
				: ft_treeinsertTI(node, var, SEC, NSEC);
			}
			else
				closedir(dirp);
		}
		else
			ft_error(ret, argv[index]);
		index++;
	}
	return (node);
}

static t_tree	*ft_sortAS(char **argv, t_ret *ret, t_tree *node)
{
	size_t			index;
	DIR				*dirp;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (!(dirp = opendir(argv[index])))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertAS(node, var, SEC, NSEC)
				: ft_treeinsertAS(node, var, SEC, NSEC);
			}
			else
				closedir(dirp);
		}
		else
			ft_error(ret, argv[index]);
		index++;
	}
	return (node);
}

t_tree			*ft_files(char **argv, t_list *options, t_ret *ret, t_tree *node)
{
	if (ft_lstsearch(options, 't') == 1)
		return (ft_sortTI(argv, ret, node));
	else
		return (ft_sortAS(argv, ret, node));
}
