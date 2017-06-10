/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:29:48 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/10 14:37:44 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_suite(mode_t nb)
{
	nb & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	nb & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	if (nb & S_ISUID)
		nb & S_IXUSR ? ft_putchar('s') : ft_putchar('S');
	else
		nb & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	nb & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	nb & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	if (nb & S_ISGID)
		nb & S_IXGRP ? ft_putchar('s') : ft_putchar('S');
	else
		nb & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	nb & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	nb & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	if (nb & S_ISVTX)
		nb & S_IXOTH ? ft_putchar('t') : ft_putchar('T');
	else
		nb & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
}

static void		ft_inspect_rights(mode_t nb)
{
	if (S_ISBLK(nb))
		ft_putchar('b');
	if (S_ISCHR(nb))
		ft_putchar('c');
	if (S_ISLNK(nb))
		ft_putchar('l');
	if (S_ISDIR(nb))
		ft_putchar('d');
	if (S_ISREG(nb))
		ft_putchar('-');
	if (S_ISSOCK(nb))
		ft_putchar('s');
	if (S_ISFIFO(nb))
		ft_putchar('p');
	ft_suite(nb);
}

static void		ft_print_name(char *str, char *path, mode_t nb)
{
	size_t			len;
	char			link[1024];

	if (S_ISLNK(nb))
	{
		ft_putstr(str);
		ft_putstr(" -> ");
		if ((len = readlink(str, link, sizeof(link))) == (size_t)-1 &&
			(len = readlink(path, link, sizeof(link))) == (size_t)-1)
		{
			perror(str);
			ft_putendl("lol");
			return ;
		}
		link[len] = '\0';
		ft_putendl(link);
	}
	else
		ft_putendl(str);
}

static void		ft_printinfo(char *str, char *path, struct stat buf)
{
	ft_putstr("\t");
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
	{
		ft_putnbr(major(buf.st_rdev));
		ft_putstr(",  ");
		ft_putnbr(minor(buf.st_rdev));
	}
	else
		ft_putnbr(buf.st_size);
	ft_putstr("\t");
	ft_printtime(buf.st_mtimespec.tv_sec);
	ft_putstr("\t");
	ft_print_name(str, path, buf.st_mode);
}

void			ft_printlong(char *str, char *path, t_tree *options)
{
	struct stat		buf;

	if (lstat(path, &buf) == 0 || lstat(str, &buf) == 0)
	{
		ft_inspect_rights(buf.st_mode);
		ft_putstr("\t");
		ft_putnbr(buf.st_nlink);
		ft_putstr("\t");
		ft_printowner(buf, options);
		ft_printinfo(str, path, buf);
	}
	else
	{
		ft_putstr("./ft_ls: ");
		perror(str);
		return ;
	}
}
