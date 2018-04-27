/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:45:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/27 05:08:07 by ardurand         ###   ########.fr       */
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
			//printf("id %d\n", proc->id);
			//ft_putendl("proc killed");
			tmp = *list;
			*list = (*list)->next;
			ft_memdel((void**)&tmp);
		}
		else
		{
			printf("le vainqueur est le joueur numero : %d\n", proc->id);
			ft_memdel((void**)list);
		}
	}
	else
	{
		while (tmp)
		{
			if (proc == tmp->next)
			{
				printf("id %d\n", proc->id);
				ft_putendl("proc killed");
				tmp->next = proc->next;
				ft_memdel((void**)&proc);
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
		//ft_putendl("coucou");
		if (tmp->live_period == 0)
			kill_process(tmp, list);
		else
			tmp->live_period = 0;
		//reset_process_counter(tmp);
		tmp = tmp->next;
	}
	if (!(*list))
	{
		ft_putendl("Tous les joueurs sont morts");
		//sleep(20);
		exit(1);
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
