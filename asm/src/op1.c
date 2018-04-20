/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:05:29 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/20 18:18:51 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Vérification que chaque op possède les bons arguments
*/
int	ft_live(char *line, int index)
{
	char *tmp;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "live") != 0)
		return (0);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	if (isdir(tmp) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}

int	ft_ld(char *line, int index)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "ld") != 0)
		return (0);
	tmp = ft_strsub(line, 2, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 2)
		msg_error(ERR_ARG, index);
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(sp[1]) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}

int	ft_st(char *line, int index)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "st") != 0)
		return (0);
	tmp = ft_strsub(line, 2, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 2)
		msg_error(ERR_NBR_ARG, index);
	if (isreg(sp[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(sp[1]) == 0 && isindir(sp[1]) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}

int ft_add(char *line, int index)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "add") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isreg(sp[0]) == 0 && isreg(sp[1]) == 0 && isreg(sp[2]) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}

int	ft_sub(char *line, int index)
{
	char *tmp;
	char **sp;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "sub") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(sp) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isreg(sp[0]) == 0 && isreg(sp[1]) == 0 && isreg(sp[2]) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}
