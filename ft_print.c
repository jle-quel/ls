/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:28:23 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 18:31:30 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_printfiles_inorder(t_tree *files, int flag)
{
	CHK_CV(files);
	if (flag == 1)
	{
		ft_printfiles_inorder(files->right, flag);
		ft_printlong(files->name, files->path);
		ft_printfiles_inorder(files->left, flag);
	}
	else
	{
		ft_printfiles_inorder(files->right, flag);
		ft_putendl(files->name);
		ft_printfiles_inorder(files->left, flag);
	}
}

void 	ft_printfiles_order(t_tree *files, int flag)
{
	CHK_CV(files);
	if (flag == 1)
	{
		ft_printfiles_order(files->left, flag);
		ft_printlong(files->name, files->path);
		ft_printfiles_order(files->right, flag);
	}
	else
	{
		ft_printfiles_order(files->left, flag);
		ft_putendl(files->name);
		ft_printfiles_order(files->right, flag);
	}
}
