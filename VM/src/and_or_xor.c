/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:04:22 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/01 22:24:23 by cboiron          ###   ########.fr       */
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
	printf("resultat = %d \n", proc->reg[arg[2] - 1]);
}

void	param_op(t_vm *vm, t_proc *proc, int *arg)
{
	int	pc;

	proc->pc++;
	pc = proc->pc + 1;
	printf("case = %d\n", vm->arena[pc]);
	printf("pc = %d\n", pc);
	if (PARAM1 == REG)
	{
		arg[0] = get_reg(vm, &pc);
		if (!is_reg(arg[0]))
			return ;
		arg[0] = proc->reg[arg[0] - 1];
	}
	else if (PARAM1 == INDIRECT)
		arg[0] = get_ind(vm, &pc);
	else if (PARAM1 == DIRECT)
		arg[0] = get_dir(vm, &pc, proc->instruction);
	printf("pc arg 1 =  %d\n", pc);
	if (PARAM2 == REG)
	{
		arg[1] = get_reg(vm, &pc);
		if (!(is_reg(arg[1])))
			return ;
		arg[1] = proc->reg[arg[1] - 1];
	}
	else if (PARAM2 == INDIRECT)
		arg[1] = get_ind(vm, &pc);
	else if (PARAM2 == DIRECT)
		arg[1] = get_dir(vm, &pc, proc->instruction);
	printf("pc arg 2 =  %d\n", pc);
	arg[2] = get_reg(vm, &pc);
	if (!is_reg(arg[2]))
		return ;
	choose_op(arg, proc);
	proc->pc = pc;
	printf("pc fin = %d\n", pc);
}
