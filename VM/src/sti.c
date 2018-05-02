/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:55:45 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 01:13:21 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
/*
sti r2,%4,%5 sti copie REG_SIZE octet de r2 a l’adresse (4 + 5) 
	Les paramètres 2 et 3 sont des index. Si les paramètres 2 ou 3 
	sont des registres, on utilisera leur contenu comme un index.
	REG
	REG INDIRECT DIRECT
	REG DIRECT
*/

void	sti(t_vm *vm, t_proc *proc)
{
	int	registre;
	int	pc;
	int	arg2;
	int	arg3;
	int	adress;

	adress = 0;

	ft_putendl("je fais un sti");
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
	printf("arg2 %d \n", arg2);
	printf("arg3 %d \n", arg3);
	adress = arg2 + arg3;
	printf("somme %d \n", adress);
	adress = adress % IDX_MOD;
	proc->pc = pc;
	write_in_memory(vm, registre, proc->save_pc + adress);
}






















/*

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
		arg2 = get_value(vm, mod(proc->save_pc + arg1, MEM_SIZE));
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
*/
