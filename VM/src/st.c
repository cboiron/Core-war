/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 05:17:20 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/29 02:21:40 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	ft_putendl("je fais un st");
	int	arg1;
	int	arg2;
	int	pc_debut;

	//printf("pc = %d\n", proc->pc);
	pc_debut = proc->pc;
	proc->pc += 2;
	arg1 = get_reg(vm, &(proc->pc));
	printf("arg1 = %d\n", arg1);
	printf("contenu du registre  = %d\n", proc->reg[arg1 - 1]);
	if (proc->parametres_types[1] == REG)
		arg2 = get_reg(vm, &(proc->pc));
	else
		arg2 = (short)get_ind(vm, &(proc->pc));
	if (!is_reg(arg1) || (proc->parametres_types[1] == REG && !is_reg(arg2)))
		return ;
	printf("arg2 = %d\n", arg2);
	printf("arg2 = %d\n", arg2 % IDX_MOD);
	pc_debut = proc->pc;
	if (proc->parametres_types[1] == REG)
		proc->reg[arg2] = proc->reg[arg1];
	else
	{
		write_in_memory(vm, proc->reg[arg1 - 1], pc_debut + (arg2 % IDX_MOD));
	}
}
