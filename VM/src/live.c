/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:41:15 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/27 04:46:57 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	int	dir;
	//ft_printf("Le joueur %s est en vie", "Clement");
	//*i += 5;
	//printf("avant get %x\n",vm->arena[proc->pc]);
	proc->pc++;
	dir = get_dir(vm, &(proc->pc), 1);
	//printf("apres get %x\n",vm->arena[proc->pc]);
//	proc->pc += 5;
	proc->live_period++;
	ft_printf("un processus dit que le joueur %d est en vie\n", proc->id);
}
