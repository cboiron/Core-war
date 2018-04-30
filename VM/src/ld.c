/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:57:02 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/30 11:43:24 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


int	get_value(t_vm *vm, int index)
{
	int	value;

	value = 0;
	printf("index = %d\n", index);
	printf("index modulo  = %d\n", mod(index, MEM_SIZE));
	value = (unsigned char)vm->arena[mod(index , MEM_SIZE)];
	value <<= 8;
	value += (unsigned char)vm->arena[mod(index + 1, MEM_SIZE)];
//	value += vm->arena[(index + 1)% MEM_SIZE];
	value <<= 8;
	value += (unsigned char)vm->arena[mod(index + 2, MEM_SIZE)];
//	value += vm->arena[(index + 2)% MEM_SIZE];
	value <<= 8;
	value += (unsigned char)vm->arena[mod(index + 3, MEM_SIZE)];
//	value += vm->arena[(index + 3)% MEM_SIZE];
	printf("value = %d\n", value);
	return (value);
}

void	ld(t_vm *vm, t_proc *proc)
{
	int	arg1;
	int	arg2;
	int	pc_count;

	ft_putendl("je fais un ld");
	printf("pc debut=  %d\n", proc->pc);
	printf("type first param = %d  \n", proc->parametres_types[0]);
	proc->pc++;
	pc_count = proc->pc + 1;
	if (proc->parametres_types[0] == DIRECT)
	{
		arg1 = get_dir(vm, &pc_count, proc->instruction);
		printf("direct =  %d\n", arg1);
	}
	else if (proc->parametres_types[0] == INDIRECT)
	{
		arg1 = (short)get_ind(vm, &pc_count);
		printf("indirect =  %d\n", arg1);
		arg1 = arg1 % IDX_MOD;
		arg1 = get_value(vm, pc_count + (arg1));
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
	printf("pc fin =  %d\n", proc->pc);
	int	i;

	i = 0;
	while (i < 16)
	{
		printf("Le registre %d contient la valeur : %d    \n", i + 1, proc->reg[i]);
	i++;
	}
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
