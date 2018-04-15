/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:10:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/15 16:36:33 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** On ajoute à buff un element label
*/
void	add_label(char *line, t_parsing **buff)
{
	t_parsing	*tmp;

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			tmp->content = ft_strdup(line);
			tmp->format = 1;
			if (buff)
			{
				if (tmp)
					tmp->next = *buff;
				*buff = tmp;
			}
			else
			{
				*buff = tmp;
				tmp->next = NULL;
			}
		}
}

/*
** On ajoute à buff un élément instruction
*/
void	add_instru(char *line, t_parsing **buff)
{
	t_parsing	*tmp;

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			tmp->content = ft_strdup(line);
			tmp->format = 2;
			if (buff)
			{
				if (tmp)
					tmp->next = *buff;
				*buff = tmp;
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
	t_parsing	*tmp;

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			tmp->content = ft_strdup(line);
			tmp->format = 3;
			if (buff)
			{
				if (tmp)
					tmp->next = *buff;
				*buff = tmp;
			}
			else
			{
				*buff = tmp;
				tmp->next = NULL;
			}
		}
}
