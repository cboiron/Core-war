/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:55:45 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/02 23:07:36 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_vm *vm, t_proc *proc)
{
	ft_putendl("je fais un sti ---------------------------------------------");

	int	arg1;
	int	arg2;
	int	arg3;
	int	pc;

	proc->pc++;
	pc = proc->pc + 1;
	arg1 = get_reg(vm, &pc);
	if (PARAM2 == REG)
		arg2 = get_reg(vm, &pc);
	else if (PARAM2 == DIRECT)
		arg2 = (short)get_dir(vm, &pc, proc->instruction);
	else if (PARAM2 == INDIRECT)
	{
		arg2 = (short)get_ind(vm, &pc);
		arg2 = get_value_2(vm, mod(proc->save_pc + arg1, MEM_SIZE));
	}
	if (PARAM3 == REG)
		arg3 = get_reg(vm, &pc);
	else if (PARAM3 == DIRECT)
		arg3 = (short)get_dir(vm, &pc, proc->instruction);
	if ((PARAM1 == REG && !is_reg(arg1)) ||
			(PARAM2 == REG && !is_reg(arg2)) ||
			(PARAM3 == REG && !is_reg(arg3)))
		return ;
	if (PARAM2 == REG)
		arg2 = proc->reg[arg2 - 1];
	if (PARAM3 == REG)
		arg3 = proc->reg[arg3 - 1];
	printf("arg 1 %d \n",arg1);
	printf("arg 2 %d \n",arg2);
	printf("arg 3 %d \n",arg3);
	write_in_memory(vm, arg1, proc->save_pc + (arg2 + arg3) % IDX_MOD);
	proc->pc = pc;
}
