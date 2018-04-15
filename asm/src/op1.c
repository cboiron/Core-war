/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:05:29 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/15 13:46:10 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Vérification que chaque op possède les bons arguments
*/
int	ft_live(char *line)
{
	char *tmp;

	tmp = ft_strsub(line, 0, 4);
	if (ft_strcmp(tmp, "live") != 0)
		return (0);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	if (isdir(tmp) == 0)
		return (0);
	return (1);
}

int	ft_ld(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 2);
	if (ft_strcmp(tmp, "ld") != 0)
		return (0);
	tmp = ft_strsub(line, 2, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 2)
		return (0);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0)
		return (0);
	if (isreg(sp[1]) == 0)
		return (0);
	return (1);
}

int	ft_st(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 2);
	if (ft_strcmp(tmp, "st") != 0)
		return (0);
	tmp = ft_strsub(line, 2, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 2)
		return (0);
	if (isreg(sp[0]) == 0)
		return (0);
	if (isreg(sp[1]) == 0 && isindir(sp[1]) == 0)
		return (0);
	return (1);
}

int ft_add(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "add") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		return (0);
	if (isreg(sp[0]) == 0 && isreg(sp[1]) == 0 && isreg(sp[2]) == 0)
		return (0);
	return (1);
}

int	ft_sub(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "sub") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		return (0);
	if (isreg(sp[0]) == 0 && isreg(sp[1]) == 0 && isreg(sp[2]) == 0)
		return (0);
	return (1);
}
