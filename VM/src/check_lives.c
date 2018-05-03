/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:45:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 12:28:32 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_process(t_proc *proc, t_proc **list)
{
	t_proc	*tmp;
	t_proc *previous;
	t_proc *nextone;

	tmp = NULL;
	if (proc == *list)
	{
		if ((*list)->next != NULL)
		{
			tmp = *list;
			*list = (*list)->next;
			ft_strdel((char**)&tmp);
		}
		else
		{
			printf("le vainqueur est le joueur numero : %d\n", proc->id);
			ft_strdel((char**)list);
		}
	}
	else
	{
		tmp = *list;
		printf("debut_else\n");
		while (tmp != proc && tmp->next)
		{
			previous = tmp;
			tmp = tmp->next;
			nextone = tmp->next;
		}
		printf("before\n");
		if (tmp != NULL && tmp == proc)
		{
			free(tmp);
			tmp = NULL;
			previous->next = nextone;
		}
		else 
		{
			ft_printf("ceci n'est pas un message.\n");
			exit(EXIT_FAILURE);
		}
	}
}
void	check_lives(t_vm *vm, t_proc **list)
{
	t_proc	*tmp;

	tmp = *list;
	while (tmp)
	{
		ft_printf("boucle\n");
		if (tmp->live_period == 0)
			kill_process(tmp, list);
		else
			tmp->live_period = 0;
		tmp = tmp->next;
	}
	if (!(*list))
	{
		ft_putendl("Tous les joueurs sont morts");
		exit(1);
	}
	ft_printf("CHECKING| total_lives %d | last_check %d\n", vm->total_lives_period, vm->last_check);
	ft_printf("cycle to die  %d\n", vm->cycle_to_die);
	//sleep(4);
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
