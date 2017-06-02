/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 12:04:24 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printERROR(char c)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ./ft_ls [-Rralt] [file ...]");
}

void	ft_parsing(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] != 'R' || str[index] != 'r' || str[index] != 'a' || str[index] != 'l' || str[index] != '-' || str[index] != 't')
		{
			ft_printERROR(str[index]);
			exit (1);
		}
		index++;
	}
}

t_list	*ft_populateOP(char **argv)
{
	size_t	index;
	t_list	*node;

	index = 0;
	node = NULL;
	while (argv[index] && argv[0][index] == '-')
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

int		main(int argc, char **argv)
{
	t_list	*options;
	(void)argc;

	options = ft_populateOP(argv + 1);
	return (0);
}
