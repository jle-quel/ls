/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:20:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/03 13:43:40 by jle-quel         ###   ########.fr       */
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

t_tree		*ft_treeinsertTI(t_tree *node, t_info var, time_t sec, long nsec)
{
	if (node == NULL)
		return (ft_treenew(var, sec, nsec));
	else if (sec > node->sec)
		node->left = ft_treeinsertTI(node->left, var, sec, nsec);
	else if (sec < node->sec)
		node->right = ft_treeinsertTI(node->right, var, sec, nsec);
	else if (sec == node->sec)
	{
		if (nsec > node->nsec)
			node->left = ft_treeinsertTI(node->left, var, sec, nsec);
		else if (nsec <= node->nsec)
			node->right = ft_treeinsertTI(node->right, var, sec, nsec);
	}
	return (node);
}
