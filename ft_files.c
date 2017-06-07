/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:55:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/07 15:07:13 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_tree	*ft_files_tispec(char **argv, t_ret *ret, t_tree *node)
{
	size_t			index;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (!S_ISDIR(buf.st_mode) || S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsert_ti(node, var, SEC, NSEC)
				: ft_treeinsert_ti(node, var, SEC, NSEC);
			}
		}
		else
			ft_error(ret, argv[index]);
		index++;
	}
	return (node);
}

static t_tree	*ft_files_ti(char **argv, t_ret *ret, t_tree *node)
{
	size_t			index;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (!S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsert_ti(node, var, SEC, NSEC)
				: ft_treeinsert_ti(node, var, SEC, NSEC);
			}
		}
		else
			ft_error(ret, argv[index]);
		index++;
	}
	return (node);
}

static t_tree	*ft_files_asspec(char **argv, t_ret *ret, t_tree *node)
{
	size_t			index;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (!S_ISDIR(buf.st_mode) || S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsert_as(node, var, SEC, NSEC)
				: ft_treeinsert_as(node, var, SEC, NSEC);
			}
		}
		else
			ft_error(ret, argv[index]);
		index++;
	}
	return (node);
}

static t_tree	*ft_files_as(char **argv, t_ret *ret, t_tree *node)
{
	size_t			index;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (!S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsert_as(node, var, SEC, NSEC)
				: ft_treeinsert_as(node, var, SEC, NSEC);
			}
		}
		else
			ft_error(ret, argv[index]);
		index++;
	}
	return (node);
}

t_tree			*ft_files(char **argv, t_tree *option, t_ret *ret, t_tree *node)
{
	if (ft_treesearch(option, 't') == 1)
	{
		return (ft_treesearch(option, 'l') == 1)
		? ft_files_tispec(argv, ret, node)
		: ft_files_ti(argv, ret, node);
	}
	else
	{
		return (ft_treesearch(option, 'l') == 1)
		? ft_files_asspec(argv, ret, node)
		: ft_files_as(argv, ret, node);
	}
}
