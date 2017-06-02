/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:55:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 16:27:30 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(t_ret *ret)
{
	perror("./ft_ls");
	ret->error = errno;
}

t_tree	*ft_files(char **argv, t_list *options, t_ret *ret)
{
	(void)options;
	size_t			index;
	DIR				*dirp;
	t_tree			*node;
	struct stat		buf;

	index = ft_index(argv);
	node = NULL;
	while (argv[index])
	{
		if (lstat(argv[index], &buf) == 0)
		{
			if (!(dirp = opendir(argv[index])))
				ft_putendl(argv[index]);
			else
				closedir(dirp);
		}
		else
			ft_error(ret);
		index++;
	}
	return (node);
}
