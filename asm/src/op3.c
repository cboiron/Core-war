/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:29:30 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/15 16:28:18 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_sti(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "sti") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		return (0);
	if (isreg(sp[0]) == 0)
		return (0);
	if (isreg(sp[1]) == 0 && isindir(sp[1]) == 0 && isdir(sp[1]) == 0)
		return (0);
	if (isreg(sp[2]) == 0 && isdir(sp[2]) == 0)
		return (0);
	return (1);
}

int	ft_fork(char *line)
{
	char	*tmp;

	tmp = ft_strsub(line, 0, 4);
	if (ft_strcmp(tmp, "fork") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	if (isdir(tmp) == 0)
		return (0);
	return (1);
}

int ft_lld(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "lld") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 2)
		return (0);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0)
		return (0);
	if (isreg(sp[1]) == 0)
		return (0);
	return (1);
}

int ft_lldi(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 4);
	if (ft_strcmp(tmp, "lldi") != 0)
		return (0);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		return (0);
	if (isreg(sp[0]) == 0 && isindir(sp[0]) == 0 && isdir(sp[0]) == 0)
		return (0);
	if (isreg(sp[1]) == 0 && isdir(sp[1]) == 0)
		return (0);
	if (isreg(sp[2]) == 0)
		return (0);
	return (1);
}

int ft_lfork(char *line)
{
	char *tmp;

	tmp = ft_strsub(line, 0, 5);
	if (ft_strcmp(tmp, "lfork") != 0)
		return (0);
	tmp = ft_strsub(line, 5, ft_strlen(line));
	if (isdir(tmp) == 0)
		return (0);
	return (1);
}
