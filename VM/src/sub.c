/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:13:50 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/03 08:53:31 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub(t_vm *vm, t_proc *proc)
{
	int	r1;
	int	r2;
	int	r3;
	int	pc;

	proc->pc++;
	pc = proc->pc + 1;
	r1 = get_reg(vm, &pc);
	r2 = get_reg(vm, &pc);
	r3 = get_reg(vm, &pc);
	if (is_reg(r1) && is_reg(r2) && is_reg(r3))
	{
		proc->reg[r3 - 1] = proc->reg[r1 - 1] - proc->reg[r2 - 1];
		if (proc->reg[r3 - 1] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
		proc->pc = pc;
	}
}
