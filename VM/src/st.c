/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 02:54:45 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/21 03:04:25 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	ft_putendl("je fais un st");
	/*
	printf("type du param : %d  .\n", proc->parametres_types[0]);
	printf("type du param : %d  .\n", proc->parametres_types[1]);
	printf("type du param : %d  .\n", proc->parametres_types[2]);
	*/
	int	arg1;
	int	arg2;
	int	pc_debut;

	pc_debut = proc->pc;
	arg1 = get_reg(vm, &(proc->pc));
	if (proc->parametres_types[1] == REG)
		arg2 = get_reg(vm, &(proc->pc));
	else
		arg2 = get_ind(vm, &(proc->pc));
	if (!is_reg(arg1) || (proc->parametres_types[1] == REG && !is_reg(arg2)))
		return ;
	if (proc->parametres_types[1] == REG)
		proc->reg[arg2] = proc->reg[arg1];
	else
	{
		write_in_memory(vm, proc->reg[arg1 - 1], (pc_debut - 2) + (arg2 % IDX_MOD));
	}
}
