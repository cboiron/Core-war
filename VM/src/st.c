/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 02:54:45 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/19 04:44:00 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_vm *vm, t_proc *proc)
{
	ft_putendl("je fais un st");
	printf("type du param : %d  .\n", proc->parametres_types[0]);
	printf("type du param : %d  .\n", proc->parametres_types[1]);
	printf("type du param : %d  .\n", proc->parametres_types[2]);
	int	arg1;
	int	arg2;

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
		
	}
	/*
	(*i)++;
	// registre source
	// si registre == 0 : carry = 1
	// sinon carry = 0
	*i += 1;
	if (vm->arena[*i] == 112)
	{
		// registre
		*i += 1;
	}
	else if (vm->arena[*i] == 80)
	{
		// index
		*i += 2;
	}
	*/
}
