/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:37:29 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/15 16:27:21 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_and(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "and") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		return (0);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0 && isreg(sp[0]) == 0)
		return (0);
	if (isdir(sp[1]) == 0 && isindir(sp[1]) == 0 && isreg(sp[1]) == 0)
		return (0);
	if (isreg(sp[2]) == 0)
		return (0);
	return (1);
}

int	ft_or(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 2);
	if (ft_strcmp(tmp, "or") != 0)
		return (0);
	tmp = ft_strsub(line, 2, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		return (0);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0 && isreg(sp[0]) == 0)
		return (0);
	if (isdir(sp[1]) == 0 && isindir(sp[1]) == 0 && isreg(sp[1]) == 0)
		return (0);
	if (isreg(sp[2]) == 0)
		return (0);
	return (1);
}

int	ft_xor(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "xor") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		return (0);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0 && isreg(sp[0]) == 0)
		return (0);
	if (isdir(sp[1]) == 0 && isindir(sp[1]) == 0 && isreg(sp[1]) == 0)
		return (0);
	if (isreg(sp[2]) == 0)
		return (0);
	return (1);
}

int	ft_zjmp(char *line)
{
	char *tmp;

	tmp = ft_strsub(line, 0, 4);
	if (ft_strcmp(tmp, "zjmp") != 0)
		return (0);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	if (isdir(tmp) == 0)
		return (0);
	return (1);
}

int ft_ldi(char *line)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "ldi") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		return (0);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0 && isreg(sp[0]) == 0)
		return (0);
	if (isdir(sp[1]) == 0 && isreg(sp[1]) == 0)
		return (0);
	if (isreg(sp[2]) == 0)
		return (0);
	return (1);
}
