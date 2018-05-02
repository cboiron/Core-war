/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 08:32:19 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 01:30:22 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_vm *vm, t_proc *proc)
{
	//(*i)++;
	ft_putendl("je fais un aff");
	int	arg1;
	int	pc;

	proc->pc++;
	pc = proc->pc + 1;
	arg1 = get_reg(vm, &pc);
	if (!is_reg(arg1))
		return ;
	arg1 = proc->reg[arg1 - 1];
	ft_printf("Aff : %C\n", arg1 % 256);
	if (arg1 % 256 == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = pc;
}
