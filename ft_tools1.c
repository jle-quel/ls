/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:17:32 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 18:42:36 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		index++;
	return (index);
}

void	ft_error(t_ret *ret, char *str)
{
	ft_putstr("./ft_ls: ");
	perror(str);
	ret->error = errno;
}
