/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:13:50 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/29 02:45:09 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_vm *vm, t_proc *proc)
{
	ft_putendl("je fais un add ");
	int	r1;
	int	r2;
	int	r3;
	int	pc;

	proc->pc++;
	pc = proc->pc;
	if (vm->arena[pc] != 84)
		return ;
	pc++;
	r1 = get_reg(vm, &pc);
	r2 = get_reg(vm, &pc);
	r3 = get_reg(vm, &pc);
	if (is_reg(r1) && is_reg(r2) && is_reg(r3))
	{
		proc->reg[r3] = proc->reg[r1] + proc->reg[r2];
		if (proc->reg[r3] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
		proc->pc = pc;
	}
}
