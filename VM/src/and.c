/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:26:44 by cboiron           #+#    #+#             */
/*   Updated: 2018/03/25 08:28:04 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_par(int source, int *i)
{
	if (source == 1)
	{
		(*i)++;
		// registre
	}
	else if (source == 2)
	{
		*i += 4;
		// direct de 4 octets
	}
	else if (source == 3)
	{
		*i += 2;
		//index 2 octets
	}
}

void	and(t_vm *vm, int *i)
{
	/*
	int		source1;
	int		source2;

	source1 = vm->arena[*i] >> 6;
	source2 = vm->arena[*i] << 2;
	source2 = vm->arena[*i] >> 6;
	get_par(source1, i);
	get_par(source2, i);
	*/

	// faire un & entre les deux parametres, stocker dans le registre
	// si res = 0, carry = 1, sinon 0
}
