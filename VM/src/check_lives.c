/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:45:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/14 17:51:24 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_process(t_proc *proc, t_proc **list)
{
	t_proc	*tmp;
	t_proc	*next;

	tmp = *list;
	if (proc == *list)
	{
		if ((*list)->next != NULL)
		{
			printf("id %d\n", proc->id);
			ft_putendl("proc killed");
			tmp = *list;
			*list = (*list)->next;
			ft_memdel((void**)&tmp);
		}
		else
		{
			printf("id %d\n", proc->id);
			ft_putendl("proc killed");
			ft_memdel((void**)list);
		}
	}
	else
	{
	ft_putendl("go list");
		while (tmp->next)
		{
			if (proc == tmp->next)
			{
				printf("id %d\n", proc->id);
				ft_putendl("proc killed");
				tmp->next = proc->next;
				free(proc);
			}
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
	}
}

void	check_lives(t_vm *vm, t_proc **list)
{
	t_proc	*tmp;

	tmp = *list;
	while (tmp)
	{
		ft_putendl("coucou");
		if (tmp->live_period == 0)
			kill_process(tmp, list);
		else
			tmp->live_period = 0;
			//reset_process_counter(tmp);
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
	vm->cycle_before_checking = vm->cycle_to_die;
}
