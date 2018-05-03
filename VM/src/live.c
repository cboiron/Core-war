/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:41:15 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/04 00:21:57 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	int	dir;
	int	i;

	i = 0;
	proc->pc++;
	dir = get_dir(vm, &(proc->pc), 1);
	proc->live_period++;
	vm->total_lives_period++;
	while (proc->id != vm->tab_champ[i].id)
		i++;
	ft_printf("Un processus dit que le joueur %d (%s) est en vie\n", proc->id,
			vm->tab_champ[i].name);
}
