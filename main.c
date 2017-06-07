/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/07 13:24:06 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_directional(t_tree *options, t_tree *files, t_tree *directories)
{
	int		display;
	t_info	var;

	display = 0;
	if (options && !directories && !files)
	{
		var.name = ft_strdup(".");
		var.path = ft_strdup(".");
		directories = ft_treenew(var, 0, 0);
	}
	if ((directories && files) || (ft_treelen(directories) > 1))
		display = 1;
	ft_treesearch(options, 'r') == 1
	? ft_launcher1(options, directories, display)
	: ft_launcher2(options, directories, display);
}

int		main(int argc, char **argv)
{
	t_ret	ret;
	t_tree	*node;
	t_tree	*options;
	t_tree	*files;
	t_tree	*directories;

	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "--") == 0))
		ft_read(NULL, ".");

	node = NULL;
	options = ft_options(argv + 1, node);
	ft_treeclr(node);

	if ((files = ft_files(argv + 1, options, &ret, node)))
		ft_printfiles(files, options);
	ft_treeclr(node);
	directories = ft_directories(argv + 1, options, node);
	ft_treeclr(node);
	ft_directional(options, files, directories);
	return (ret.error);
}
