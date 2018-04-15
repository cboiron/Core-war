/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:00:24 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/15 15:06:57 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_aff(char *line)
{
	char *tmp;

	tmp = ft_strsub(line, 0, 3);
	if (ft_strcmp(tmp, "aff") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	if (isreg(tmp) == 0)
		return (0);
	return (1);
}
