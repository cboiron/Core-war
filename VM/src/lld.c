/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 04:45:35 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/01 23:01:35 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld(t_vm *vm, t_proc *proc)
{
	ft_putendl("je fais un lld");
	int		arg1;
	int		arg2;
	int		pc;

	proc->pc++;
	pc = proc->pc + 1;
	arg1 = get_dir(vm, &pc, 2);
	if (PARAM2 == REG)
		arg2 = get_reg(vm, &pc);
	else
		arg2 = get_ind(vm, &pc);
	if ((PARAM2 == REG && is_reg(arg2)) || PARAM2 == INDIRECT)
	{
		proc->reg[arg2 - 1] = arg1;
		if (arg1 == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else
		return ;
	proc->pc = pc;
}
