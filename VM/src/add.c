/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:13:50 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/27 01:03:52 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_vm *vm, t_proc *proc)
{
	int	r1;
	int	r2;
	int	r3;

	r1 = get_reg(vm, &(proc->pc));
	r2 = get_reg(vm, &(proc->pc));
	r3 = get_reg(vm, &(proc->pc));
	if (is_reg(r1) && is_reg(r2) && is_reg(r3))
	{
		proc->reg[r3] = proc->reg[r1] + proc->reg[r2];
		if (proc->reg[r3] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	//ft_putendl("je fais un add ");
}
