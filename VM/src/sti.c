/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:55:45 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 16:33:11 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_vm *vm, t_proc *proc)
{
	int	registre;
	int	pc;
	int	arg2;
	int	arg3;
	int	adress;

	adress = 0;
	proc->pc++;
	pc = proc->pc + 1;
	registre = get_reg(vm, &pc);
	if (!is_reg(registre))
		return ;
	registre = proc->reg[registre - 1];
	if (PARAM2 == REG)
	{
		arg2 = get_reg(vm, &pc);
		if (!is_reg(arg2))
			return ;
		arg2 = proc->reg[arg2 - 1];
	}
	else if (PARAM2 == INDIRECT)
	{
		arg2 = (short)get_ind(vm, &pc);
		arg2 = get_value(vm, mod(proc->save_pc + arg2, MEM_SIZE));
	}
	else if (PARAM2 == DIRECT)
		arg2 = (short)get_dir(vm, &pc, proc->instruction);
	if (PARAM3 == REG)
	{
		arg3 = get_reg(vm, &pc);
		if (!is_reg(arg3))
			return ;
		arg3 = proc->reg[arg3 - 1];
	}
	else
		arg3 = (short)get_dir(vm, &pc, proc->instruction);
	adress = arg2 + arg3;
	adress = adress % IDX_MOD;
	proc->pc = pc;
	write_in_memory(vm, registre, proc->save_pc + adress);
}
