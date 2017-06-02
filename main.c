/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 18:35:18 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_ret	ret;
	t_tree	*node;
	t_list	*options;
	t_tree	*files;

	if (argc == 1)
		return (-1);

	node = NULL;
	options = ft_options(argv + 1);
	files = ft_files(argv + 1, options, &ret, node);
	free(node);
	node = NULL;
	ft_printfiles_order(files, ft_lstsearch(options, 'l'));

	return (ret.error);
}
