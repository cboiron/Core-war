/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:10:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/21 23:27:48 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Calcule et stocke la taille des buff->content dans buff->size
*/
unsigned int	size_to_add()
{

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
	t_parsing	*tmp;
	t_parsing	*tmp2;

	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
		{
			tmp->content = ft_strdup(line);
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
