/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:57:02 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 07:59:08 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


long int	get_value(t_vm *vm, int index)
{
	long int	value;

	value = 0;
	value = (unsigned char)vm->arena[mod(index , MEM_SIZE)];
	value <<= 8;
	value += (unsigned char)vm->arena[mod(index + 1, MEM_SIZE)];
	value <<= 8;
	value += (unsigned char)vm->arena[mod(index + 2, MEM_SIZE)];
	value <<= 8;
	value += (unsigned char)vm->arena[mod(index + 3, MEM_SIZE)];
	printf("value = %ld\n", value);
	return (value);
}

void	ld(t_vm *vm, t_proc *proc)
{
	long int	arg1;
	long int	arg2;
	int	pc_count;

	proc->pc++;
	pc_count = proc->pc + 1;
	if (PARAM1 == DIRECT)
	{
		arg1 = get_dir(vm, &pc_count, proc->instruction);
	}
	else if (PARAM1 == INDIRECT)
	{
		arg1 = (short)get_ind(vm, &pc_count);
		arg1 = arg1 % IDX_MOD;
		arg1 = get_value(vm, mod(proc->save_pc + arg1, MEM_SIZE));
	}
	else
		return ;
	arg2 = get_reg(vm, &pc_count);
	if (!is_reg(arg2))
		return ;
	proc->reg[arg2 - 1] = arg1;
	if (arg1 == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = pc_count;
}

/*
   void	ld(t_vm *vm, t_proc *proc)
{
	int		arg1;
	int		arg2;
	long long 	int		value;

	proc->pc += 2;
	value = 0;
	arg1 = 0;
	printf("case  =  %d\n", vm->arena[proc->pc]);
	printf("pc  =  %d\n", proc->pc);
	if (proc->parametres_types[0] == DIRECT)
	{
		printf("arg1 = %d\n", arg1);
		arg1 = get_dir(vm, &(proc->pc), proc->instruction);
		printf("arg1 = %d\n", arg1);
		if (arg1 < 0)
			arg1 = arg1 % -IDX_MOD;
		value = get_value(vm, proc->pc + arg1);
		printf("seg = %lld\n", value);
		arg2 = get_reg(vm, &(proc->pc));
		proc->reg[arg2 - 1] = value;
		printf("segfault = %lld\n", value);
		return ;
	}
	else if (proc->parametres_types[0] == INDIRECT)
		arg1 = get_reg(vm, &(proc->pc));
	printf("arg 1 = %d\n", arg1);
	arg2 = get_reg(vm, &(proc->pc));
	if ((proc->parametres_types[0] == REG && is_reg(arg2))
			|| proc->parametres_types[0] == INDIRECT)
	{
		proc->reg[arg2 - 1] = arg1;
		if (arg1 == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	ft_putendl("je fais un ld");
}
*/
