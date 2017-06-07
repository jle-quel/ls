/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directories.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 11:45:48 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/07 15:10:32 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_tree	*ft_directories_tispec(char **argv, t_tree *node)
{
	size_t			index;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsert_ti(node, var, SEC, NSEC)
				: ft_treeinsert_ti(node, var, SEC, NSEC);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directories_ti(char **argv, t_tree *node)
{
	size_t			index;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (S_ISDIR(buf.st_mode) || S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsert_ti(node, var, SEC, NSEC)
				: ft_treeinsert_ti(node, var, SEC, NSEC);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directories_asspec(char **argv, t_tree *node)
{
	size_t			index;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsert_as(node, var, SEC, NSEC)
				: ft_treeinsert_as(node, var, SEC, NSEC);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directories_as(char **argv, t_tree *node)
{
	size_t			index;
	t_info			var;
	struct stat		buf;

	index = ft_index(argv);
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (S_ISDIR(buf.st_mode) || S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsert_as(node, var, SEC, NSEC)
				: ft_treeinsert_as(node, var, SEC, NSEC);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directories(char **argv, t_tree *options, t_tree *node)
{
	if (ft_treesearch(options, 't') == 1)
	{
		return (ft_treesearch(options, 'l') == 1)
		? ft_directories_tispec(argv, node)
		: ft_directories_ti(argv, node);
	}
	else
	{
		return (ft_treesearch(options, 'l') == 1)
		? ft_directories_asspec(argv, node)
		: ft_directories_as(argv, node);
	}
}
