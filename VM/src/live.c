/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:41:15 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 18:35:37 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	int	dir;

	proc->pc++;
	dir = get_dir(vm, &(proc->pc), 1);
	proc->live_period++;
	vm->total_lives_period++;
	ft_printf("un processus dit que le joueur %d est en vie\n", proc->id);
}
