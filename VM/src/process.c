/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 02:04:46 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/07 04:00:34 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*new_process(t_champ champ)
{
	t_proc	*proc;
	int		i;

	i = 0;
	proc = ft_memalloc(sizeof(t_proc));
	proc->id = champ.id;
	proc->carry = 0;
	proc->live_period = 0;
	proc->pc = 0;
	proc->cycle_to_wait = 0;
	proc->instruction = 0;
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
