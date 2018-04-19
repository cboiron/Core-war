/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:36:46 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/19 17:21:17 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	size_line(char *line, t_asm *env)
{
	char	**separate;
	t_op	*op_tab;
	int		i;
	int		j;

	op_tab = get_ops();
	i = search_char(line, ':');
	if (i != -1)
	i = -1;
	separate = ft_strsplit(line, ' ');
	while (op_tab[++i].name)
		if (ft_strcmp(op_tab[i].name, separate[0]) == 0)
			break;
	env->header->prog_size++;
	if (op_tab[i].carry)
		env->header->prog_size++;
	j = 0;
	while (separate[++j])
		if (isreg(separate[j]))
			env->header->prog_size += REG_SIZE;
		else if (isdir(separate[j]))
			env->header->prog_size += DIR_SIZE;
		else if (isindir(separate[j]))
			env->header->prog_size += IND_SIZE;
}
//inutilisée pour l'instant !
void		verif_size(char *line, t_asm *env)
{
	int		verif;
	int		i;

	verif = 0;
	line = ft_epur_str(line);
	if ((i = search_char(line, ':')) > 0)
	{
		line = ft_strsub(line, i + 1, ft_strlen(line));
	}
	size_line(line, env);
	free(line);
}
