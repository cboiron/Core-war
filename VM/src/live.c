/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:41:15 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/14 17:06:52 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	//ft_printf("Le joueur %s est en vie", "Clement");
	//*i += 5;
	proc->pc += 5;
	proc->live_period++;
	ft_printf("live pc = %d\n", proc->pc);
}
