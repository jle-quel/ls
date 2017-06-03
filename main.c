/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/03 11:36:15 by jle-quel         ###   ########.fr       */
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
	ft_treeclr(node);

	return (ret.error);
}
