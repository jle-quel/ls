/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:28:23 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/03 12:07:53 by jle-quel         ###   ########.fr       */
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
}

void 	ft_printfiles(t_tree *files, t_list *options)
{
	ft_lstsearch(options, 'r') == 1
	? ft_printIN(files, ft_lstsearch(options, 'l'))
	: ft_printOR(files, ft_lstsearch(options, 'l'));
	// !directories ? : ft_putendl(""); // TO ADD AFTER IN THE MAIN
}
