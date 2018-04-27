/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:36:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/27 01:01:16 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	check_reg(t_proc *proc, int arg1, int arg2)
{
	if (proc->parametres_types[0] == REG)
		arg1 = proc->reg[arg1 - 1];
	if (proc->parametres_types[1] == REG)
		arg2 = proc->reg[arg2 - 1];
	if (proc->instruction == 10)
	{
		arg1 %= IDX_MOD;
		arg2 %= IDX_MOD;
		//ft_putendl("je fait un ldi");
	}
	else if (proc->instruction == 14)
	{
	//	ft_putendl("je fait un lldi");
	}
	return (arg1 + arg2 % MEM_SIZE);
}

int	ldi_2(t_vm *vm, int adress, t_proc *proc)
{
	int	value;

	value = vm->arena[adress];
	value <<= 8;
	value = vm->arena[(adress + 1) % MEM_SIZE];
	value <<= 8;
	value = vm->arena[(adress + 2) % MEM_SIZE];
	value <<= 8;
	value = vm->arena[(adress + 3) % MEM_SIZE];
	return (value);
}

void	ldi(t_vm *vm, t_proc *proc)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	pc_debut;

//	printf("case avant  = %d\n", vm->arena[proc->pc]);
//	printf("pc before = %d\n", proc->pc);
	pc_debut = proc->pc;
	if (proc->parametres_types[0] == REG)
		arg1 = get_reg(vm, &(proc->pc));
	else if (proc->parametres_types[0] == INDIRECT)
		arg1 = get_ind(vm, &(proc->pc));
	else if (proc->parametres_types[0] == DIRECT)
		arg1 = get_ind(vm, &(proc->pc));
//	printf("pc arg1  = %d\n", proc->pc);
//	printf("case apres  = %d\n", vm->arena[proc->pc]);
	if (proc->parametres_types[1] == REG)
		arg2 = get_reg(vm, &(proc->pc));
	else if (proc->parametres_types[1] == DIRECT)
		arg2 = get_ind(vm, &(proc->pc));
//	printf("pc arg2  = %d\n", proc->pc);
	arg3 = get_reg(vm, &(proc->pc));
//	printf("pc arg3  = %d\n", proc->pc);
	if ((proc->parametres_types[0] == REG && !is_reg(arg1)) ||
			(proc->parametres_types[1] == REG && !is_reg(arg2)) ||
			(proc->parametres_types[2] == REG && !is_reg(arg3)))
		return ;
	proc->reg[arg3 - 1] = pc_debut + ldi_2(vm, check_reg(proc, arg1, arg2), proc);
	if (proc->reg[arg3 - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc++;
	//printf("case apres  = %d\n", vm->arena[proc->pc]);
	//printf("case apres + 1 = %d\n", vm->arena[proc->pc + 1]);
//	printf("pc after  = %d\n", proc->pc);
}
