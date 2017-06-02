/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:20:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 18:50:09 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_treeclr(t_tree *node)
{
	CHK_CV(node);
	ft_treeclr(node->left);
	ft_treeclr(node->right);
	free(node->name);
	if (node->path)
		free(node->path);
	node->name = NULL;
	node->path = NULL;
	free(node);
	node = NULL;
}

char	*ft_path(char *directory, char *name)
{
	char	*path;

	path = ft_memalloc(ft_strlen(directory) + 1 + ft_strlen(name) + 1);
	ft_strcpy(path, directory);
	ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}

void	ft_info(t_info *var, char *name, char *directory)
{
	var->name = ft_strdup(name);
	if (directory)
		var->path = ft_path(directory, name);
	else
		var->path = NULL;
}

t_tree		*ft_treenew(t_info var, time_t sec, long nsec)
{
	t_tree	*node;

	node = (t_tree*)malloc(sizeof(t_tree));
	node->name = ft_strdup(var.name);
	if (var.path)
		node->path = ft_strdup(var.path);
	else
		node->path = NULL;
	node->sec = sec;
	node->nsec = nsec;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_tree		*ft_treeinsertAS(t_tree *node, t_info var, time_t sec, long nsec)
{
	if (node == NULL)
		return (ft_treenew(var, sec, nsec));
	else if (ft_strcmp(var.name, node->name) <= 0)
		node->left = ft_treeinsertAS(node->left, var, sec, nsec);
	else if (ft_strcmp(var.name, node->name) > 0)
		node->right = ft_treeinsertAS(node->right, var, sec, nsec);
	return (node);
}
