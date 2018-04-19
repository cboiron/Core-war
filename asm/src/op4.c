/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:00:24 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/19 01:36:19 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_aff(char *line, int index)
{
	char *tmp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "aff") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	if (isreg(tmp) == 0)
		msg_error(ERR_ARG, index);
	return (1);
}
