/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:41:15 by cboiron           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/03 15:11:10 by abrichar         ###   ########.fr       */
=======
/*   Updated: 2018/05/03 14:48:21 by cboiron          ###   ########.fr       */
>>>>>>> 405a037630d60cf01b85389a4f36b3ac22b2d998
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
