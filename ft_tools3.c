/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 14:18:59 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/10 14:23:48 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(t_ret *ret, char *str)
{
	ft_putstr("./ft_ls: ");
	perror(str);
	ret->error = errno;
}

void	ft_printtime(time_t ti)
{
	size_t	index;
	time_t	currtime;
	char	*mtime;

	index = 0;
	currtime = time(0);
	mtime = ctime(&ti);
	if (ti - currtime > 15770000 || currtime - ti > 15770000)
	{
		while (index < 11)
			ft_putchar(mtime[index++]);
		while (index < 20)
			index++;
		while (index < 24)
			ft_putchar(mtime[index++]);
	}
	else
	{
		while (index < 16)
			ft_putchar(mtime[index++]);
	}
}

void	ft_printowner(struct stat buf, t_tree *options)
{
	struct passwd	*id;
	struct group	*gid;

	if (ft_treesearch(options, 'n') == 1)
	{
		ft_putnbr(buf.st_uid);
		ft_putstr("\t");
		if (ft_treesearch(options, 'o') != 1)
			ft_putnbr(buf.st_gid);
	}
	else
	{
		if (!(id = getpwuid(buf.st_uid)))
			ft_putnbr(buf.st_uid);
		else
			ft_putstr(id->pw_name);
		ft_putstr("\t");
		if (ft_treesearch(options, 'o') != 1)
		{
			if (!(gid = getgrgid(buf.st_gid)))
				ft_putnbr(buf.st_gid);
			else
				ft_putstr(gid->gr_name);
		}
	}
}
