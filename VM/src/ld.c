/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:57:02 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/27 01:01:09 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_vm *vm, t_proc *proc)
{
	int		arg1;
	int		arg2;

	arg1 = get_dir(vm, &(proc->pc), 2);
	if (proc->parametres_types[1] == REG)
		arg2 = get_reg(vm, &(proc->pc));
	else
		arg2 = get_ind(vm, &(proc->pc));
	arg2 = arg2 % IDX_MOD;
	if ((proc->parametres_types[1] == REG && is_reg(arg2))
			|| proc->parametres_types[1] == INDIRECT)
	{
		proc->reg[arg2 - 1] = arg1;
		if (arg1 == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	//ft_putendl("je fais un ld");
}
