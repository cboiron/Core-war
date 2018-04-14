/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:45:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/14 16:36:05 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_process(t_proc *proc, t_proc **list)
{
	t_proc	*tmp;

	ft_putendl("proc killed");
	tmp = *list;
	if (proc == *list)
	{
		if ((*list)->next != NULL)
		{
			proc->next = NULL;
			free(proc);
		}
	}
	else
	{
		while (tmp->next)
		{
			if (proc == tmp->next)
			{
				tmp->next = proc->next;
				free(proc);
			}
		tmp = tmp->next;
		}
	}
}

void	reset_process_counter(t_proc *proc)
{
	proc->live_period = 0;
}

void	check_lives(t_vm *vm, t_proc **list)
{
	ft_putendl("coucou");
	t_proc	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->live_period == 0)
			kill_process(tmp, list);
		else
			reset_process_counter(tmp);
		tmp = tmp->next;
	}
	if (vm->total_lives_period > NBR_LIVE ||
			vm->last_check == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->last_check = 0;
	}
	else
		vm->last_check++;
}
