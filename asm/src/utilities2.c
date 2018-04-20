/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:24:50 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/20 15:27:10 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_param(char *param)
{
	if (isreg(param))
		return (1);
	if (isdir(param))
		return (2);
	if (isindir(param))
		return (3);
	return (0);
}

int	tab_len(char **tab)
{
	int i;

	i = -1;
	while (tab[++i]);
	return (i);
}

uint64_t	reverse_bits(uint64_t val)
{
	uint64_t	res;

	res = 0;
	while (val)
	{
		res <<= 8;
		res |= val & 0xff;
		val >>= 8;
	}
	return (res);
}
