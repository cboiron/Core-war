/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:45:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 14:41:11 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_process(t_proc *proc, t_proc **list)
{
	t_proc	*tmp;

	tmp = *list;
	if (tmp == proc)
	{
		tmp->alive = -1;
		//*list = tmp->next;
		//free(proc);
		//proc = NULL;
	}
	else
	{
		while (proc->next != proc && tmp->next != NULL)
			tmp = tmp->next;
		tmp->alive = -1;
		//tmp->next = proc->next;
		//free(proc);
		//proc = NULL;
	}
}

int		someone_is_alive(t_proc *list)
{
	t_proc	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->alive == 1)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_lives(t_vm *vm, t_proc **list)
{
	t_proc	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		ft_printf("boucle\n");
		if (tmp->live_period == 0 && tmp->alive >= 0)
		{
			tmp->alive = -1;
		}
		else
			tmp->live_period = 0;
		tmp = tmp->next;
	}
	if (someone_is_alive(*list) == 0)
	{
		ft_putendl("Tous les joueurs sont morts");
		exit(1);
	}
	ft_printf("CHECKING| total_lives %d | last_check %d\n", vm->total_lives_period, vm->last_check);
	ft_printf("cycle to die  %d\n", vm->cycle_to_die);
	sleep(4);
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
