/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:04:22 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/28 14:31:14 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	choose_op(int *arg, t_proc *proc)
{
	if (proc->instruction == 6)
		proc->reg[arg[2] - 1] = arg[0] & arg[1];
	else if (proc->instruction == 7)
		proc->reg[arg[2] - 1] = arg[0] | arg[1];
	else if (proc->instruction == 8)
		proc->reg[arg[2] - 1] = arg[0] ^ arg[1];
	if (proc->reg[arg[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}

void	param_op(t_vm *vm, t_proc *proc, int *arg)
{
	if (proc->parametres_types[0] == REG)
	{
		arg[0] = get_reg(vm, &(proc->pc));
		arg[0] = proc->reg[arg[0] - 1];
	}
	else if (proc->parametres_types[0] == INDIRECT)
		arg[0] = get_ind(vm, &(proc->pc));
	else if (proc->parametres_types[0] == DIRECT)
		arg[0] = get_dir(vm, &(proc->pc), proc->instruction);
	if (proc->parametres_types[1] == REG)
	{
		arg[1] = get_reg(vm, &(proc->pc));
		arg[1] = proc->reg[arg[1] - 1];
	}
	else if (proc->parametres_types[1] == INDIRECT)
		arg[1] = get_ind(vm, &(proc->pc));
	else if (proc->parametres_types[1] == DIRECT)
		arg[1] = get_dir(vm, &(proc->pc), proc->instruction);
	arg[2] = get_reg(vm, &(proc->pc));
	if ((proc->parametres_types[0] == REG && !is_reg(arg[0])) ||
			(proc->parametres_types[1] == REG && !is_reg(arg[1])) ||
			(proc->parametres_types[2] == REG && !is_reg(arg[2])))
		return ;
	choose_op(arg, proc);
}
