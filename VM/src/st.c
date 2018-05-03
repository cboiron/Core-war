/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 05:17:20 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/02 02:18:39 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	ft_putendl("je fais un st");
	int	arg1;
	int	arg2;
	int	pc;

	//printf("pc = %d\n", proc->pc);
	proc->pc++;
	pc = proc->pc + 1;
	arg1 = get_reg(vm, &pc);
	printf("arg1 = %d\n", arg1);
	printf("contenu du registre  = %d\n", proc->reg[arg1 - 1]);
	if (PARAM2 == REG)
		arg2 = get_reg(vm, &pc);
	else
		arg2 = (short)get_ind(vm, &pc);
	if (!is_reg(arg1) || (PARAM2 == REG && !is_reg(arg2)))
		return ;
	printf("arg2 = %d\n", arg2);
	if (PARAM2 == REG)
		proc->reg[arg2] = proc->reg[arg1];
	else
	{
		arg2 %= IDX_MOD;
		write_in_memory(vm, proc->reg[arg1 - 1], proc->save_pc + mod(arg2, MEM_SIZE));
	}
	proc->pc = pc;
}

/*
 * int	i;

	i = 0;
	while (i < 16)
	{
		printf("Le registre %d contient la valeur : %d    \n", i + 1, proc->reg[i]);
	i++;
	}
}*/
