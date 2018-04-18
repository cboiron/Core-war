/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:48:10 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/18 20:42:36 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Ces fonctions servent à vérifier la longueur du nom et du com
** ainsi que de les stocker dans la variable env
*/
static int check_size2(char *line, char *macro)
{
	if (ft_strcmp(macro, NAME_CMD_STRING) == 0)
		if (ft_strlen(line) <= PROG_NAME_LENGTH)
			return (1);
	if (ft_strcmp(macro, COMMENT_CMD_STRING) == 0)
		if (ft_strlen(line) <= COMMENT_LENGTH)
			return (1);
	return (0);
}

static int check_size(char *line, t_asm *env, char *macro)
{
	if (ft_strcmp(macro, NAME_CMD_STRING) == 0)
	{
		if (check_size2(line, macro) == 1)
		{
			ft_strcpy(env->header->prog_name, line);
			free(line);
			return (1);
		}
	}
	if (ft_strcmp(macro, COMMENT_CMD_STRING) == 0)
	{
		if (check_size2(line, macro) == 1)
		{
			ft_strcpy(env->header->prog_name , line);
			free(line);
			return (1);
		}
	}
	free(line);
	return (0);
}

int dump_header(char *line, t_asm *env, char *macro)
{
	int		i;
	int		j;
	char	*tmp;
	char	*sub;

	i = search_char(line, '"') + 1;
	tmp = ft_strsub(line, i, ft_strlen(line));
	j = search_char(tmp, '"');
	sub = ft_strsub(tmp, 0, j);
	free(tmp);
	return (check_size(sub, env, macro));
}
