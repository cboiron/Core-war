/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:10:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/23 20:34:50 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Calcule et stocke la taille des buff->content dans buff->size
*/
unsigned int	size_instru(t_parsing *tmp)
{
	char **splited;
	unsigned int size;
	int i;
	t_op	actual;

	size = 0;
	i = -1;
	splited = ft_strsplit(tmp->content, ' ');
	size += 1;
	actual = find_opcode(splited[0]);
	splited = ft_strsplit(splited[1], ',');
	clear_split(splited);
	while (++i < tab_len(splited))
	{
		if (check_param(splited[i]) == REG_CODE)
			size++;
		else if (check_param (splited[i]) == IND_CODE)
		{
			if ((actual.opcode == 1 || actual.opcode == 2 || actual.opcode >= 6
				|| actual.opcode <= 8 || actual.opcode == 13) && splited[i][1]
				== ':')
				size += 4;
			else
				size += 2;
		}
		else
			size += 2;
	}
	return (size);
}
/*
** On ajoute à buff un element label
*/
void	add_label(char *line, t_parsing **buff)
{
	t_parsing	*tmp;
	t_parsing	*tmp2;

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			tmp->content = ft_strdup(line);
			tmp->size = 1;
			tmp->label = 1;
			tmp->next = NULL;
			if (*buff)
			{
				tmp2 = *buff;
				while (tmp2->next)
					tmp2 = tmp2->next;
				tmp2->next = tmp;
			}
			else
				*buff = tmp;
		}
}

/*
** On ajoute à buff un élément instruction
*/
void	add_instru(char *line, t_parsing **buff)
{
	t_parsing	*tmp;
	t_parsing	*tmp2;
	t_op		actual;
	char		*name;

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			tmp->content = ft_epur_str(ft_strdup(line));
			name = ft_strsub(tmp->content, 0, search_char(tmp->content, ' '));
			actual = find_opcode(name);
			tmp->size = size_instru(tmp);
			tmp->label = 0;
			tmp->next = NULL;
			if (*buff)
			{
				tmp2 = *buff;
				while (tmp2->next)
					tmp2 = tmp2->next;
				tmp2->next = tmp;
			}
			else
			{
				*buff = tmp;
				tmp->next = NULL;
			}
		}
}

/*
** On ajoute à buff un élément label+instruction
*/
void	add_lab_and_instru(char *line, t_parsing **buff)
{
	int i;
	char *sub;

	i = search_char(line, ' ');
	sub = ft_strsub(line, 0, i + 1);
	sub = ft_epur_str(sub);
	add_label(sub, buff);
	free(sub);
	sub = ft_strsub(line, i + 1, ft_strlen(line) - i);
	sub = ft_epur_str(sub);
	add_instru(sub, buff);
	free(sub);
}
