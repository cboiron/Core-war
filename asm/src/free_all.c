/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 00:49:32 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/04 01:19:03 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_all(t_asm *env)
{
	t_parsing	*tmp;

	free(env->champ_name);
	tmp = env->buff;
	while (tmp->next)
	{
		free(&tmp->content);
//		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
}
