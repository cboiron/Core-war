/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 02:04:46 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/21 01:06:52 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*new_process(t_champ champ, int num_player, t_vm *vm)
{
	t_proc	*proc;
	int		i;

	i = 0;
	proc = ft_memalloc(sizeof(t_proc));
	proc->id = champ.id;
	proc->carry = 0;
	proc->live_period = 0;
	proc->pc = (MEM_SIZE / vm->nbr_next) * num_player;
	//printf("num joueur : %d , pc = %d \n", num_player, proc->pc);
	proc->cycle_to_wait = -1;
	proc->instruction = 0;
	proc->next = NULL;
	proc->parametres_types[0] = 0;
	proc->parametres_types[1] = 0;
	proc->parametres_types[2] = 0;
	while (i < REG_NUMBER)
	{
		proc->reg[i] = 0;
		i++;
	}
	proc->reg[0] = proc->id;
	return (proc);
}

void	add_process(t_proc **list, t_proc *proc)
{
	if (*list)
		proc->next = *list;
	*list = proc;
}

void	free_process(t_proc *proc)
{

}
