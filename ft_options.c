/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:04:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/10 14:20:39 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_error(char c)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ./ft_ls [-Rraltno] [file ...]");
}

static void		ft_parsing(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] != 'R' && str[index] != 'r' && str[index] != 'a' &&
			str[index] != 'l' && str[index] != 't' && str[index] != 'n' &&
			str[index] != 'o')
		{
			ft_print_error(str[index]);
			exit(1);
		}
		index++;
	}
}

t_tree			*ft_options(char **argv, t_tree *node)
{
	size_t	index;
	t_info	var;

	index = 0;
	while (argv[index] && argv[0][index] == '-' && argv[0][1] != '-')
	{
		ft_parsing(argv[index] + 1);
		ft_info(&var, argv[index], NULL);
		node == NULL
		? node = ft_treeinsert_as(node, var, 0, 0)
		: ft_treeinsert_as(node, var, 0, 0);
		argv++;
	}
	return (node);
}
