/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:45:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/28 09:52:14 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_process(t_proc *proc, t_proc **list)
{
	t_proc	*tmp;

	tmp = NULL;
	tmp = *list;
	if (proc == *list)
	{
		if ((*list)->next != NULL)
		{
			printf("id1 %d\n", proc->id);
			ft_putendl("proc killed1");
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
			if (tmp->next && proc == tmp->next)
			{
				printf("id2 %d\n", proc->id);
				ft_putendl("proc killed2");
				tmp->next = proc->next;
				//ft_memdel((void**)proc);
				ft_putendl("proc killed2");
			}
			if (tmp->next != NULL)
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
		vm->total_lives_period = 0;
	}
	else
		vm->last_check++;
	vm->cycle_before_checking = vm->cycle_to_die;
}
