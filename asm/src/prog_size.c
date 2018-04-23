/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:36:46 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/23 23:36:54 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		verif_size(t_asm *env)
{
	unsigned int size_total;
	t_parsing *tmp;

	env->header->prog_size = 0;
	size_total = 0;
	tmp = env->buff;
	if (!env->buff)
		size_total = tmp->size;
	while (tmp->next)
	{
		tmp = tmp->next;
	    size_total += tmp->size;
		ft_printf("tmp : %s ==> %d\n", tmp->content, tmp->size);
	}
	env->header->prog_size = size_total;
}
