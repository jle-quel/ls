/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:04:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/06 16:55:14 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_printERROR(char c)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ./ft_ls [-Rralt] [file ...]");
}

static void		ft_parsing(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] != 'R' && str[index] != 'r' && str[index] != 'a' &&
			str[index] != 'l' && str[index] != 't')
		{
			ft_printERROR(str[index]);
			exit (1);
		}
		index++;
	}
}

t_tree				*ft_options(char **argv, t_tree *node)
{
	size_t	index;
	t_info	var;

	index = 0;
	while (argv[index] && argv[0][index] == '-' && argv[0][1] != '-')
	{
		ft_parsing(argv[index] + 1);
		var.name = ft_strdup(argv[index]);
		var.path = NULL;
		// ft_info(&var, argv[index], NULL);
		node == NULL
		? node = ft_treeinsertTI(node, var, 0, 0)
		: ft_treeinsertTI(node, var, 0, 0);
		argv++;
	}
	return (node);
}
