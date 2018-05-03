/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:27:37 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/04 00:21:30 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_vm *vm, t_proc *proc)
{
	int	dir;
	int	pc;

	proc->pc++;
	pc = proc->pc;
	dir = (short)get_dir(vm, &pc, 9);
	if (dir < 0)
		dir %= -IDX_MOD;
	else
		dir %= IDX_MOD;
	if (proc->carry == 1)
	{
		proc->pc = mod(dir + pc, MEM_SIZE);
		return ;
	}
	else
		proc->pc = pc;
}
