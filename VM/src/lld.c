/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 04:45:35 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 14:48:27 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long int	get_value_2(t_vm *vm, int index)
{
	long int	value;

	value = 0;
	value = (unsigned char)vm->arena[mod(index , MEM_SIZE)];
	value <<= 8;
	value += (unsigned char)vm->arena[mod(index + 1, MEM_SIZE)];
	return (value);
}

void	lld(t_vm *vm, t_proc *proc)
{
	int		arg1;
	int		arg2;
	int		pc;

	proc->pc++;
	arg1 = 0;
	pc = proc->pc + 1;
	if (PARAM1 == DIRECT)
		arg1 = get_dir(vm, &pc, proc->instruction);
	else if (PARAM1 == INDIRECT)
	{
		arg1 = (short)get_ind(vm, &pc);
		arg1 = get_value_2(vm, mod(proc->save_pc + arg1, MEM_SIZE));
	}
	arg2 = get_reg(vm, &pc);
	if (is_reg(arg2))
	{
		proc->reg[arg2 - 1] = arg1;
		if (arg1 == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else
		return ;
	proc->pc = pc;
}
