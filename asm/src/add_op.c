/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:10:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/17 13:34:43 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** On ajoute à buff un element label
*/
void	add_label(char *line, t_parsing **buff)
{
	t_parsing	*tmp;
	t_parsing	*tmp2;

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			ft_putstr("addlabel\n");
			tmp->content = ft_strdup(line);
			tmp->format = 1;
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

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			tmp->content = ft_strdup(line);
			tmp->format = 2;
			if (*buff)
			{
				tmp2 = *buff;
				while (tmp2->next)
					tmp2 = tmp2->next;
				tmp2->next = tmp;
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
	t_parsing	*tmp2;

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			tmp->content = ft_strdup(line);
			tmp->format = 3;
			tmp->next = NULL;
			if (*buff)
			{
				tmp2 = *buff;
				while (tmp2->next)
					tmp2 = tmp2->next;
				ft_putstr("rofl\n");
				tmp2->next = tmp;
			}
			else
				*buff = tmp;
		}
}
