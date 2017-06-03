/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:04:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/03 13:30:30 by jle-quel         ###   ########.fr       */
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

t_list			*ft_options(char **argv)
{
	size_t	index;
	t_list	*node;

	index = 0;
	node = NULL;
	while (argv[index] && argv[0][index] == '-' && argv[0][1] != '-')
	{
		ft_parsing(argv[index] + 1);
		if (node == NULL)
			node = ft_lstnew(argv[index] + 1, 0);
		else
			ft_lstaddnext(&node, ft_lstnew(argv[index] + 1, 0));
		argv++;
	}
	return (node);
}
