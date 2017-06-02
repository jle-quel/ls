/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:55:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 15:21:10 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_tree	*ft_files(char **argv, t_list *options, t_ret *ret)
{
	(void)options;
	size_t			index;
	t_tree			*node;
	struct stat		buf;

	index = ft_index(argv);
	node = NULL;
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			ft_putendl(argv[index]);
		}
		else
		{
			perror("./ft_ls");
			ret->error = errno;
		}
		index++;
	}
	return (node);
}
