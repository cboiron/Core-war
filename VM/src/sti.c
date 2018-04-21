/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:55:45 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/21 04:47:20 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_vm *vm, t_proc *proc)
{
	ft_putendl("je fais un sti");

	int	arg1;
	int	arg2;
	int	arg3;
	int	pc_debut;

	pc_debut = proc->pc;
	arg1 = get_reg(vm, &(proc->pc));
	if (proc->parametres_types[1] == REG)
		arg2 = get_reg(vm, &(proc->pc));
	else if (proc->parametres_types[1] == DIRECT)
		arg2 = get_dir(vm, &(proc->pc), proc->instruction);
	else if (proc->parametres_types[1] == INDIRECT)
		arg2 = get_ind(vm, &(proc->pc));
	if (proc->parametres_types[2] == REG)
		arg3 = get_reg(vm, &(proc->pc));
	else if (proc->parametres_types[1] == DIRECT)
		arg3 = get_dir(vm, &(proc->pc), proc->instruction);
	if ((proc->parametres_types[0] == REG && !is_reg(arg1)) ||
			(proc->parametres_types[1] == REG && !is_reg(arg2)) ||
			(proc->parametres_types[2] == REG && !is_reg(arg3)))
		return ;
	if (proc->parametres_types[1] == REG)
		arg2 = proc->reg[arg2 - 1];
	if (proc->parametres_types[2] == REG)
		arg3 = proc->reg[arg3 - 1];
	write_in_memory(vm, arg1, pc_debut - 2 + (arg2 + arg3) % IDX_MOD);
}
