/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 00:17:52 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/17 13:34:15 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	checking_op(char *line, t_asm *env)
{
	char *tmp;

	if (env->verif_name == 0 || env->verif_com == 0)
		return (0);
	tmp = rm_comment(line);
	if (is_label_only(tmp) == 1)
	{
		ft_putstr("t1\n");
		add_label(tmp, &env->buff);
		return (1);
	}
	if (check_instruction(tmp) == 1)
	{
		ft_putstr("t2\n");
		add_instru(tmp, &env->buff);
		return (1);
	}
	if (check_lab_and_instru(tmp) == 1)
	{
		ft_putstr("t3\n");
		add_lab_and_instru(tmp, &env->buff);
		return (1);
	}
	return (0);
}

/*
** Fonction pour checker ligne par ligne
*/
static int	check_line(char *line, char *tmp, t_asm *env)
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
	if (is_header(line, COMMENT_CMD_STRING) == 1 && env->verif_com == 0)
	{
		if (dump_header(tmp, env, COMMENT_CMD_STRING) == 1)
		{
			env->verif_com = 1;
			return (1);
		}
	}
	if (checking_op(line, env) == 1)
		return (1);
	return (0);
}

/*
** fonction de départ du parsing du fichier
*/

void		parsing(char *file, t_asm *env)
{
	int		fd;
	char	*line;
	int		index;
	char	*tmp;

	index = 1;
	if (!(fd = open(file, O_RDONLY)))
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_epur_str(line);
		if (check_line(tmp, line, env) == 0)
		{
			ft_printf("%s\n", line);
			ft_printf("erreur de syntaxe à la ligne %d\n", index);
			exit(EXIT_FAILURE);
		}
		free(line);
		free(tmp);
		index++;
	}
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
}
