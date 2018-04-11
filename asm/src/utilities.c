/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 00:17:45 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/11 00:32:30 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** le caractère que tu cherches, trouver tu dois
*/
int	search_char(char *line, char c)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == c)
			return (i);
	}
	return (-1);
}
