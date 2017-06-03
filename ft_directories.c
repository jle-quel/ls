/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directories.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 11:45:48 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/03 14:11:16 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// FOR THE REVERSE SORT WITH THE DIRECTORIES, WHEN YOU SEND THE DIRECTORIES
// TO THE READ FUNCTION SEND IT BACKWARD

t_tree	*ft_directoriesTI_SPEC(char **argv, t_tree *node)
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
			if ((dirp = opendir(argv[index])) && !S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertTI(node, var, SEC, NSEC)
				: ft_treeinsertTI(node, var, SEC, NSEC);
				closedir(dirp);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directoriesTI(char **argv, t_tree *node)
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
			if ((dirp = opendir(argv[index])))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertTI(node, var, SEC, NSEC)
				: ft_treeinsertTI(node, var, SEC, NSEC);
				closedir(dirp);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directoriesAS_SPEC(char **argv, t_tree *node)
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
			if ((dirp = opendir(argv[index])) && !S_ISLNK(buf.st_mode))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertAS(node, var, SEC, NSEC)
				: ft_treeinsertAS(node, var, SEC, NSEC);
				closedir(dirp);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directoriesAS(char **argv, t_tree *node)
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
			if ((dirp = opendir(argv[index])))
			{
				ft_info(&var, argv[index], NULL);
				node == NULL
				? node = ft_treeinsertAS(node, var, SEC, NSEC)
				: ft_treeinsertAS(node, var, SEC, NSEC);
				closedir(dirp);
			}
		}
		index++;
	}
	return (node);
}

t_tree	*ft_directories(char **argv, t_tree *options, t_tree *node)
{
	if (ft_treesearch(options, 't'))
	{
		return ft_treesearch(options, 'l')
		? ft_directoriesTI_SPEC(argv, node)
		: ft_directoriesTI(argv, node);
	}
	else
	{
		return ft_treesearch(options, 'l')
		? ft_directoriesAS_SPEC(argv, node)
		: ft_directoriesAS(argv, node);
	}
}
