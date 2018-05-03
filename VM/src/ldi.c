/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:36:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/03 05:24:13 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
/*
Cette opération modifie le carry. ldi 3,%4,r1 lit IND_SIZE octets a l’adresse
: (PC + (3 % IDX_MOD)) ajoute 4 à cette valeur. On nommera S cette somme.
On lit REG_SIZE octet à l’adresse (PC + (S
	% IDX_MOD)) que l’on copie dans r1.

Les paramètres 1 et 2 sont des index.

T_REG | T_DIR | T_IND,
T_DIR | T_REG,
T_REG


*/
int	check_reg(t_proc *proc, int arg1, int arg2)
{
	printf("              arg 1 billy = %d\n", arg1);
	printf("              arg 2 = %d\n", arg2);
	if (proc->instruction == 10)
	{
		ft_putendl("je fait un ldi");
		return (mod((arg1 + arg2) % IDX_MOD, MEM_SIZE));
	}
	else if (proc->instruction == 14)
	{
		ft_putendl("je fait un lldi");
	}
	printf("somme = %d\n", arg1 + arg2);
	return (arg1 + arg2);
}

int	ldi_2(t_vm *vm, int adress)
{
	int	value;

	printf("                           adresse = %d  \n", adress);
	value = 0;
	value = vm->arena[mod(adress, MEM_SIZE)];
	value <<= 8;
	value = vm->arena[mod((adress + 1),MEM_SIZE)];
	value <<= 8;
	value = vm->arena[mod((adress + 2), MEM_SIZE)];
	value <<= 8;
	value = vm->arena[mod((adress + 3), MEM_SIZE)];
	printf("                           value = %d  \n", value);
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


	printf("contenu reg 5 %d\n", proc->reg[4]);
	if (PARAM1 == REG)
	{
		arg1 = get_reg(vm, &pc);
		if (!is_reg(arg1))
			return ;
		arg1 = proc->reg[arg1 - 1];
	}
	else if (PARAM1 == INDIRECT)
	{
	printf("indirect  \n");
		arg1 = (short)get_ind(vm, &pc);
	printf("	indirect =  %d \n", arg1);
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
	{
		ft_printf("-------------------> c est ici\n");
		arg2 = (short)get_dir(vm, &pc, proc->instruction);
		ft_printf("arg2> %d\n", arg2);
		//arg2 = (short)get_dir(vm, &pc, proc->instruction);
	}
	printf("type de arg2%d\n",PARAM2);
	arg3 = get_reg(vm, &pc);
	if (!is_reg(arg3))
		return ;
	printf("	arg1 %d \n", arg1);
	printf("	arg2 %d \n", arg2);
	printf("	arg3 %d \n", arg3);
	proc->reg[arg3 - 1] = ldi_2(vm, (proc->save_pc + check_reg(proc, arg1, arg2)));
	printf("numero de registre  = %d\n", arg3);
	printf("resultat  = %d\n", proc->reg[arg3 - 1]);
	//proc->reg[arg3 - 1] = 0;
	if (proc->reg[arg3 - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = pc;
}
