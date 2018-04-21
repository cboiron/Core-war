/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:36:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/21 04:51:45 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldi(t_vm *vm, t_proc *proc)
{
	int	arg1;
	int	arg2;
	int	arg3;

	if (proc->parametres_types[0] == REG)
		arg1 = get_reg(vm, &(proc->pc));
	else if (proc->parametres_types[0] == INDIRECT)
		arg1 = get_ind(vm, &(proc->pc));
	else if (proc->parametres_types[0] == DIRECT)
		arg1 = get_ind(vm, &(proc->pc));
	if (proc->parametres_types[1] == REG)
		arg2 = get_reg(vm, &(proc->pc));
	else if (proc->parametres_types[1] == DIRECT)
		arg2 = get_ind(vm, &(proc->pc));
	arg3 = get_reg(vm, &(proc->pc));
	if ((proc->parametres_types[0] == REG && !is_reg(arg1)) ||
			(proc->parametres_types[1] == REG && !is_reg(arg2)) ||
			(proc->parametres_types[2] == REG && !is_reg(arg3)))
		return ;
	if (proc->parametres_types[0] == REG)
		arg1 = proc->reg[arg1 - 1];
	if (proc->parametres_types[1] == REG)
		arg2 = proc->reg[arg2 - 1];
	ft_putendl("je fais un ldi");
}
