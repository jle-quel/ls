/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:00:10 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/09 11:48:16 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_check(char *str)
{
	if (ft_strcmp(str, ".") == 0 || ft_strcmp(str, "..") == 0)
		return ("EL DIABLO");
	return (NULL);
}

void	ft_recursive1(t_tree *node, t_tree *options, int flag)
{
	struct stat		buf;

	CHK_CV(node);
	ft_recursive1(node->right, options, flag);
	lstat(node->path, &buf);
	if (!S_ISLNK(buf.st_mode) && S_ISDIR(buf.st_mode) && !ft_check(node->name))
	{
		ft_putendl("");
		ft_putstr(node->path);
		ft_putendl(":");
		ft_read(options, node->path);
	}
	ft_recursive1(node->left, options, flag);
}

void	ft_recursive2(t_tree *node, t_tree *options, int flag)
{
	struct stat		buf;

	CHK_CV(node);
	ft_recursive2(node->left, options, flag);
	lstat(node->path, &buf);
	if (!S_ISLNK(buf.st_mode) && S_ISDIR(buf.st_mode) && !ft_check(node->name))
	{
		ft_putendl("");
		ft_putstr(node->path);
		ft_putendl(":");
		ft_read(options, node->path);
	}
	ft_recursive2(node->right, options, flag);
}

void	ft_handle_directions(t_tree *node, t_tree *options)
{
	if (ft_treesearch(options, 'r') == 1)
		ft_recursive1(node, options, ft_treesearch(options, 'l'));
	else
		ft_recursive2(node, options, ft_treesearch(options, 'l'));
}
