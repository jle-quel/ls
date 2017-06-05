/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:14:40 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/05 15:30:13 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_read1(t_tree *options, char *directory)
{
	DIR				*dirp;
	t_tree			*node;
	t_info			var;
	blkcnt_t		blocks;
	struct dirent	*sd;
	struct stat		buf;

	node = NULL;
	blocks = 0;
	CHK_DIR((dirp = opendir(directory)))
	while ((sd = readdir(dirp)))
	{
		ft_info(&var, sd->d_name, directory);
		if (lstat(var.path, &buf) == 0)
		{
			node == NULL
			? node = ft_treeinsertTI(node, var, SEC, NSEC)
			: ft_treeinsertTI(node, var, SEC, NSEC);
			blocks += buf.st_blocks;
		}
	}
	closedir(dirp);
	ft_display(options, node, blocks);
}

void 	ft_read2(t_tree *options, char *directory)
{
	DIR				*dirp;
	t_tree			*node;
	t_info			var;
	blkcnt_t		blocks;
	struct dirent	*sd;
	struct stat		buf;

	node = NULL;
	blocks = 0;
	CHK_DIR((dirp = opendir(directory)))
	while ((sd = readdir(dirp)))
	{
		ft_info(&var, sd->d_name, directory);
		if (lstat(var.path, &buf) == 0 && *sd->d_name != '.')
		{
			node == NULL
			? node = ft_treeinsertTI(node, var, SEC, NSEC)
			: ft_treeinsertTI(node, var, SEC, NSEC);
			blocks += buf.st_blocks;
		}
	}
	closedir(dirp);
	ft_display(options, node, blocks);
}

void 	ft_read3(t_tree *options, char *directory)
{
	DIR				*dirp;
	t_tree			*node;
	t_info			var;
	blkcnt_t		blocks;
	struct dirent	*sd;
	struct stat		buf;

	node = NULL;
	blocks = 0;
	CHK_DIR((dirp = opendir(directory)))
	while ((sd = readdir(dirp)))
	{
		ft_info(&var, sd->d_name, directory);
		if (lstat(var.path, &buf) == 0)
		{
			node == NULL
			? node = ft_treeinsertAS(node, var, SEC, NSEC)
			: ft_treeinsertAS(node, var, SEC, NSEC);
			blocks += buf.st_blocks;
		}
	}
	closedir(dirp);
	ft_display(options, node, blocks);
}

void 	ft_read4(t_tree *options, char *directory)
{
	DIR				*dirp;
	t_tree			*node;
	t_info			var;
	blkcnt_t		blocks;
	struct dirent	*sd;
	struct stat		buf;

	node = NULL;
	blocks = 0;
	CHK_DIR((dirp = opendir(directory)))
	while ((sd = readdir(dirp)))
	{
		ft_info(&var, sd->d_name, directory);
		if (lstat(var.path, &buf) == 0 && *sd->d_name != '.')
		{
			node == NULL
			? node = ft_treeinsertAS(node, var, SEC, NSEC)
			: ft_treeinsertAS(node, var, SEC, NSEC);
			blocks += buf.st_blocks;
		}
	}
	closedir(dirp);
	ft_display(options, node, blocks);
}

void	ft_read(t_tree *options, char *directory)
{
	if (ft_treesearch(options, 't') == 1)
	{
		ft_treesearch(options, 'a') == 1
		? ft_read1(options, directory)
		: ft_read2(options, directory);
	}
	else
	{
		ft_treesearch(options, 'a') == 1
		? ft_read3(options, directory)
		: ft_read4(options, directory);
	}
}
