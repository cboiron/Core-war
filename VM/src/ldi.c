/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:36:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/02 05:57:39 by cboiron          ###   ########.fr       */
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
		ft_putendl("je fait un ldi");
	}
	else if (proc->instruction == 14)
	{
		ft_putendl("je fait un lldi");
	}
	printf("arg 1 = %d\n", arg1);
	printf("arg 2 = %d\n", arg2);
	return (mod(arg1 + arg2, MEM_SIZE));
}

int	ldi_2(t_vm *vm, int adress, t_proc *proc)
{
	int	value;

	adress = mod(adress, MEM_SIZE);
	value = 0;
	value = vm->arena[adress];
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
	//printf("case avant  = %d\n", vm->arena[proc->pc]);
	//printf("pc before = %d\n", proc->pc);
	proc->pc++;
	pc = proc->pc + 1;
	if (PARAM1 == REG)
		arg1 = get_reg(vm, &pc);
	else if (PARAM1 == INDIRECT)
	{
		arg1 = (short)get_ind(vm, &pc);
	}
	else if (PARAM1 == DIRECT)
		arg1 = get_dir(vm, &pc, proc->instruction);
	//printf("pc arg1  = %d\n", proc->pc);
	//printf("case apres  = %d\n", vm->arena[proc->pc]);
	if (PARAM2 == REG)
		arg2 = get_reg(vm, &pc);
	else if (PARAM2 == DIRECT)
		arg2 = get_dir(vm, &pc, proc->instruction);
//	printf("pc arg2  = %d\n", proc->pc);
	arg3 = get_reg(vm, &pc);
	//printf("arg3  = %d\n", arg3);
	//printf("slt\n");
	if ((PARAM1 == REG && !is_reg(arg1)) ||
			(PARAM2 == REG && !is_reg(arg2)) ||
			(PARAM3 == REG && !is_reg(arg3)))
		return ;
	//printf("slt\n");
	//printf(" reg%d\n", proc->reg[arg3 - 1]);
	//printf(" value %d\n", pc_debut + ldi_2(vm, check_reg(proc, arg1, arg2), proc));
	proc->reg[arg3 - 1] = proc->save_pc + ldi_2(vm, check_reg(proc, arg1, arg2), proc);
	printf("numero de registre  = %d\n", arg3);
	printf("resultat  = %d\n", proc->reg[arg3 - 1]);
	//printf("slt\n");
	if (proc->reg[arg3 - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = pc;
	//printf("pc after = %d\n", proc->pc);
	//printf("case apres  = %d\n", vm->arena[proc->pc]);
	//printf("case apres + 1 = %d\n", vm->arena[proc->pc + 1]);
//	printf("pc after  = %d\n", proc->pc);
}
