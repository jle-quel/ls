/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:17:32 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/07 13:26:26 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	ft_treelen(t_tree *directories)
{
	if (!directories)
		return (0);
	else
		return(ft_treelen(directories->left) + 1 + ft_treelen(directories->right));
}

char	*ft_path(char *directory, char *name)
{
	char	*path;

	path = ft_memalloc(ft_strlen(directory) + 1 + ft_strlen(name) + 1);
	ft_strcpy(path, directory);
	ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}

int		ft_treesearch(t_tree *options, char c)
{
	size_t	index;

	index = 0;
	CHK_CI(options);
	ft_treesearch(options->left, c);
	while (options->name[index])
	{
		if (options->name[index] == c)
			return (1);
		index++;
	}
	return (ft_treesearch(options->right, c));
}

int		ft_lstsearch(t_list *options, char c)
{
	size_t	index;
	t_list	*temp;

	temp = options;
	while (temp)
	{
		index = 0;
		while (temp->content[index])
		{
			if (temp->content[index] == c)
				return (1);
			index++;
		}
		temp = temp->next;
	}
	return (0);
}

size_t	ft_index(char **argv)
{
	size_t	index;

	index = 0;
	while (argv[index] && *argv[index] == '-')
	{
		if (argv[index][1] == '-')
		{
			index++;
			break ;
		}
		index++;
	}
	return (index);
}

void	ft_error(t_ret *ret, char *str)
{
	ft_putstr("./ft_ls: ");
	perror(str);
	ret->error = errno;
}
