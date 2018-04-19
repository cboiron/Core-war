/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:57:02 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/19 03:51:53 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_proc *proc)
{
	int		arg1;
	int		arg2;

	arg1 = get_dir(vm, &(proc->pc), 2);
	arg2 = get_reg(vm, &(proc->pc));
	printf("arg 1  = %d \n", arg1);
	printf("num registre = %d \n", arg2);
	if (arg2 > 0 && arg2 < REG_NUMBER)
	{
		proc->reg[arg2] = arg1;
		if (arg1 == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	ft_putendl("je fais un ld");

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
