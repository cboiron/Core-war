/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:57:02 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/14 16:59:59 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_proc *proc)
{
	//(*i)++;
	/*
	if (vm->arena[*i] == 144)
	{
		*i += 4;
		//lire les 4 octets, on a le direct
	}
	else if (vm->arena[*i] == 208)
	{
		*i += 2;
		//lire les 2 octets, on a l'index
	}
	*i += 1;
	*/
	//lire l'octet suivant, on a le registre
	//copier premier param dans registre
	//si premier param = 0 alors carry = 1
	
}
