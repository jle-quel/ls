/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:00:10 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/06 19:20:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recursive2(t_tree *node, t_tree *options, int flag)
{
	struct stat		buf;

	CHK_CV(node);
	ft_handle_directions(node->left, options);
	flag == 1
	? ft_printlong(node->name, node->path)
	: ft_putendl(node->name);
	ft_handle_directions(node->right, options);
	lstat(node->path, &buf);
	if (!S_ISLNK(buf.st_mode) && S_ISDIR(buf.st_mode))
	{
		ft_putendl("");
		ft_putstr(node->path);
		ft_putendl(":");
		ft_read(options, node->path);
	}
}

void	ft_recursive1(t_tree *node, t_tree *options, int flag)
{
	struct stat		buf;

	CHK_CV(node);
	ft_handle_directions(node->right, options);
	flag == 1
	? ft_printlong(node->name, node->path)
	: ft_putendl(node->name);
	ft_handle_directions(node->left, options);
	lstat(node->path, &buf);
	if (!S_ISLNK(buf.st_mode) && S_ISDIR(buf.st_mode))
	{
		ft_putendl("");
		ft_putstr(node->path);
		ft_putendl(":");
		ft_read(options, node->path);
	}
}

void	ft_handle_directions(t_tree *node, t_tree *options)
{
	if (ft_treesearch(options, 'r') == 1)
		ft_recursive1(node, options, ft_treesearch(options, 'l'));
	else
		ft_recursive2(node, options, ft_treesearch(options, 'l'));
}
