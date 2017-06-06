/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:28:23 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/06 15:58:03 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_printIN(t_tree *files, int flag)
{
	CHK_CV(files);
	if (flag == 1)
	{
		ft_printIN(files->right, flag);
		ft_printlong(files->name, files->path);
		ft_printIN(files->left, flag);
	}
	else
	{
		ft_printIN(files->right, flag);
		ft_putendl(files->name);
		ft_printIN(files->left, flag);
	}
	free(files);
}

void 	ft_printOR(t_tree *files, int flag)
{
	CHK_CV(files);
	if (flag == 1)
	{
		ft_printOR(files->left, flag);
		ft_printlong(files->name, files->path);
		ft_printOR(files->right, flag);
	}
	else
	{
		ft_printOR(files->left, flag);
		ft_putendl(files->name);
		ft_printOR(files->right, flag);
	}
	free(files);
}

void 	ft_printfiles(t_tree *files, t_tree *options)
{
	ft_treesearch(options, 'r') == 1
	? ft_printIN(files, ft_treesearch(options, 'l'))
	: ft_printOR(files, ft_treesearch(options, 'l'));
}

void	ft_display(t_tree *options, t_tree *node, blkcnt_t blocks)
{
	if (ft_treesearch(options, 'l') == 1)
	{
		ft_putstr("total ");
		ft_putnbr(blocks);
		ft_putendl("");
	}
	ft_treesearch(options, 'r') == 1
	? ft_printIN(node, ft_treesearch(options, 'l'))
	: ft_printOR(node, ft_treesearch(options, 'l'));
}
