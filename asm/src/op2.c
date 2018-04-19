/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:37:29 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/19 01:21:04 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_and(char *line, int index)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "and") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0 && isreg(sp[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(sp[1]) == 0 && isindir(sp[1]) == 0 && isreg(sp[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(sp[2]) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}

int	ft_or(char *line, int index)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 2);
	if (ft_strcmp(tmp, "or") != 0)
		return (0);
	tmp = ft_strsub(line, 2, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0 && isreg(sp[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(sp[1]) == 0 && isindir(sp[1]) == 0 && isreg(sp[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(sp[2]) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}

int	ft_xor(char *line, int index)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "xor") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0 && isreg(sp[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(sp[1]) == 0 && isindir(sp[1]) == 0 && isreg(sp[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(sp[2]) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}

int	ft_zjmp(char *line, int index)
{
	char *tmp;

	tmp = ft_strsub(line, 0, 4);
	if (ft_strcmp(tmp, "zjmp") != 0)
		return (0);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	if (isdir(tmp) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}

int ft_ldi(char *line, int index)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "ldi") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0 && isreg(sp[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(sp[1]) == 0 && isreg(sp[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(sp[2]) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}
