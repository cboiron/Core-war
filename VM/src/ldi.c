/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:36:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/03 14:48:16 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	check_reg(t_proc *proc, int arg1, int arg2)
{
	if (proc->instruction == 10)
	{
		return (mod((arg1 + arg2) % IDX_MOD, MEM_SIZE));
	}
	return (arg1 + arg2);
}

int	ldi_2(t_vm *vm, int adress)
{
	int	value;

	value = 0;
	value = vm->arena[mod(adress, MEM_SIZE)];
	value <<= 8;
	value = vm->arena[mod((adress + 1),MEM_SIZE)];
	value <<= 8;
	value = vm->arena[mod((adress + 2), MEM_SIZE)];
	value <<= 8;
	value = vm->arena[mod((adress + 3), MEM_SIZE)];
	return (value);
}

void	ldi(t_vm *vm, t_proc *proc)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	pc;

	arg1 = 0;
	arg2 = 0;
	arg3 = 0;
	proc->pc++;
	pc = proc->pc + 1;

	if (PARAM1 == REG)
	{
		arg1 = get_reg(vm, &pc);
		if (!is_reg(arg1))
			return ;
		arg1 = proc->reg[arg1 - 1];
	}
	else if (PARAM1 == INDIRECT)
	{
		arg1 = (short)get_ind(vm, &pc);
		arg1 %= IDX_MOD;
		arg1 = get_value(vm, mod(proc->save_pc + arg1, MEM_SIZE));
	}
	else if (PARAM1 == DIRECT)
		arg1 = (short)get_dir(vm, &pc, proc->instruction);
	if (PARAM2 == REG)
	{
		arg2 = get_reg(vm, &pc);
		if (!is_reg(arg2))
			return ;
		arg2 = proc->reg[arg2 - 1];
	}
	else if (PARAM2 == DIRECT)
		arg2 = (short)get_dir(vm, &pc, proc->instruction);
	arg3 = get_reg(vm, &pc);
	if (!is_reg(arg3))
		return ;
	proc->reg[arg3 - 1] = ldi_2(vm, (proc->save_pc + check_reg(proc, arg1, arg2)));
	if (proc->reg[arg3 - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = pc;
}
