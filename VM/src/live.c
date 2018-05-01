/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:41:15 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/02 01:01:11 by cboiron          ###   ########.fr       */
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
	printf("apres get %d\n", dir);
//	proc->pc += 5;
	proc->live_period++;
	vm->total_lives_period++;
	ft_printf("un processus dit que le joueur %d est en vie\n", proc->id);
}
