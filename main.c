/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/03 13:31:10 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_ret	ret;
	t_tree	*node;
	t_list	*options;
	t_tree	*files;
	t_tree	*directories;

	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "--") == 0))
		return (-1);

	node = NULL;
	options = ft_options(argv + 1);
	if ((files = ft_files(argv + 1, options, &ret, node)))
		ft_printfiles(files, options);
	ft_treeclr(node);
	directories = ft_directories(argv + 1, options, node);
	ft_treeclr(node);
	return (ret.error);
}
