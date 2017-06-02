/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:20:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 17:17:06 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_path(char *directory, char *name)
{
	char	*path;

	path = ft_memalloc(ft_strlen(directory) + 1 + ft_strlen(name) + 1);
	ft_strcpy(path, directory);
	ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}

t_info	*ft_infonew(struct stat buf, char *name, char *directory)
{
	t_info	*var;

	CHK_CC((var = (t_info*)malloc(sizeof(t_info))));
	CHK_CC((var->name = ft_strdup(name)));
	var->path = NULL;
	if (directory)
		CHK_CC((var->path = ft_path(directory, name)));
	var->sec = buf.st_mtimespec.tv_sec;
	var->nsec = buf.st_mtimespec.tv_nsec;
	return (var);
}

t_tree	*ft_treenew(t_info *var)
{
	t_tree	*node;

	CHK_CC((node = (t_tree*)malloc(sizeof(t_tree))));
	CHK_CC((node->name = ft_strdup(var->name)));
	CHK_CC((node->path = ft_strdup(var->path)));
	node->sec = var->sec;
	node->nsec = var->nsec;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_tree		*ft_treeinsertAS(t_tree *node, t_info *var)
{
	if (node == NULL)
		return (ft_treenew(var));
	else if (ft_strcmp(var->name, node->name) <= 0)
		node->left = ft_treeinsertAS(node->left, var);
	else if (ft_strcmp(var->name, node->name) > 0)
		node->right = ft_treeinsertAS(node->right, var);
	return (node);
}
