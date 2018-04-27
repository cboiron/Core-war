/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 08:32:19 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/27 06:07:27 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_vm *vm, t_proc *proc)
{
	//(*i)++;
	ft_putendl("je fais un aff");
	int	arg1;

	arg1 = get_reg(vm, &(proc->pc));
	if (!is_reg(arg1))
		return ;
	ft_printf("Aff : %C\n", arg1 % 256);
	if (arg1 % 256 == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
