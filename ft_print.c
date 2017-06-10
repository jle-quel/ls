/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:28:23 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/10 14:12:53 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_in(t_tree *files, int flag, t_tree *options)
{
	CHK_CV(files);
	if (flag == 1)
	{
		ft_print_in(files->right, flag, options);
		ft_printlong(files->name, files->path, options);
		ft_print_in(files->left, flag, options);
	}
	else
	{
		ft_print_in(files->right, flag, options);
		ft_putendl(files->name);
		ft_print_in(files->left, flag, options);
	}
}

void	ft_print_or(t_tree *files, int flag, t_tree *options)
{
	CHK_CV(files);
	if (flag == 1)
	{
		ft_print_or(files->left, flag, options);
		ft_printlong(files->name, files->path, options);
		ft_print_or(files->right, flag, options);
	}
	else
	{
		ft_print_or(files->left, flag, options);
		ft_putendl(files->name);
		ft_print_or(files->right, flag, options);
	}
}

void	ft_printfiles(t_tree *files, t_tree *options, t_tree *directories)
{
	ft_treesearch(options, 'r') == 1
	? ft_print_in(files, ft_treesearch(options, 'l'), options)
	: ft_print_or(files, ft_treesearch(options, 'l'), options);
	if (directories)
		ft_putendl("");
}

void	ft_display(t_tree *options, t_tree *node, blkcnt_t blocks)
{
	if (ft_treesearch(options, 'l') == 1 && node)
	{
		ft_putstr("total ");
		ft_putnbr(blocks);
		ft_putendl("");
	}
	ft_treesearch(options, 'r') == 1
	? ft_print_in(node, ft_treesearch(options, 'l'), options)
	: ft_print_or(node, ft_treesearch(options, 'l'), options);
}
