/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:57:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 16:24:17 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_ret	ret;
	t_list	*options;
	t_tree	*files;

	if (argc == 1)
		return (-1);
	options = ft_options(argv + 1);
	files = ft_files(argv + 1, options, &ret);

	return (ret.error);
}
