/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:02:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/05 16:20:59 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_output(char *str)
{
	static int	index = 0;

	if (index != 0)
		ft_putendl("");
	ft_putstr(str);
	ft_putendl(":");
	index++;
}

void			ft_launcher1(t_tree *options, t_tree *directories, int display)
{
	CHK_CV(directories);
	ft_launcher1(options, directories->right, display);
	display == 0 ? : ft_output(directories->name);
	ft_read(options, directories->name);
	ft_launcher1(options, directories->left, display);
}

void			ft_launcher2(t_tree *options, t_tree *directories, int display)
{
	CHK_CV(directories);
	ft_launcher2(options, directories->left, display);
	display == 0 ? : ft_output(directories->name);
	ft_read(options, directories->name);
	ft_launcher2(options, directories->right, display);
}
