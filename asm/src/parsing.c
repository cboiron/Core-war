/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 00:17:52 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/11 00:37:20 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Fonction pour checker ligne par ligne
*/
static int check_line(char *line, char *tmp, t_asm *env)
{
	if (ft_strcmp(line, "") == 0)
		return (1);
	if (line[0] == '#')
		return (1);
	if (is_header(line, NAME_CMD_STRING) == 1 && env->verif_name == 0)
	{
		if (dump_header(tmp, env, NAME_CMD_STRING) == 1)
		{
			env->verif_name = 1;
			return (1);
		}
	}
	if (is_header(line, COMMENT_CMD_STRING) == 1 && env->verif_name == 0)
	{
		if (dump_header(tmp, env, COMMENT_CMD_STRING) == 1)
		{
			env->verif_com = 1;
			return (1);
		}
	}
	return (0);
}

/*
** fonction de départ du parsing du fichier
*/

void	parsing(char *file, t_asm *env)
{
	int		fd;
	char	*line;
	int		index;
	char	*tmp;

	if (!(fd = open(file, O_RDONLY)))
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_epur_str(line);
		if (check_line(tmp, line, env) == 0)
		{
			free(line);
			free(tmp);
		}
	}
}
