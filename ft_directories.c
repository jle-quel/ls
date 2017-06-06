/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directories.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 11:45:48 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/06 16:57:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_tree	*ft_directoriesTI_SPEC(char **argv, t_tree *node)
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
				var.name = ft_strdup(argv[index]);
				var.path = NULL;
				// ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertTI(node, var, SEC, NSEC)
				: ft_treeinsertTI(node, var, SEC, NSEC);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directoriesTI(char **argv, t_tree *node)
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
				var.name = ft_strdup(argv[index]);
				var.path = NULL;
				// ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertTI(node, var, SEC, NSEC)
				: ft_treeinsertTI(node, var, SEC, NSEC);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directoriesAS_SPEC(char **argv, t_tree *node)
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
				var.name = ft_strdup(argv[index]);
				var.path = NULL;
				// ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertAS(node, var, SEC, NSEC)
				: ft_treeinsertAS(node, var, SEC, NSEC);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directoriesAS(char **argv, t_tree *node)
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
				var.name = ft_strdup(argv[index]);
				var.path = NULL;
				// ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertAS(node, var, SEC, NSEC)
				: ft_treeinsertAS(node, var, SEC, NSEC);
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
		return ft_treesearch(options, 'l') == 1
		? ft_directoriesTI_SPEC(argv, node)
		: ft_directoriesTI(argv, node);
	}
	else
	{
		return ft_treesearch(options, 'l') == 1
		? ft_directoriesAS_SPEC(argv, node)
		: ft_directoriesAS(argv, node);
	}
}
