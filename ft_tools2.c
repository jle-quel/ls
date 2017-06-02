/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:20:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/02 14:44:34 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info		*ft_infonew(char *name, char *path, time_t sec, long nsec)
{
	t_info	*var;

	CHK_CC((var = (t_info*)malloc(sizeof(t_info))));
	CHK_CC((var->name = ft_strdup(name)));
	CHK_CC((var->path = ft_strdup(path)));
	var->sec = sec;
	var->nsec = nsec;
	return (var);
}

t_tree		*ft_treenew(t_info *var)
{
	t_tree	*node;

	CHK_CC((node = (t_tree*)malloc(sizeof(t_tree))));
	CHK_CC((node->name = ft_strsub(var->name, 0, ft_strlen(var->name))));
	CHK_CC((node->path = ft_strsub(var->path, 0, ft_strlen(var->name))));
	node->sec = var->sec;
	node->nsec = var->nsec;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
