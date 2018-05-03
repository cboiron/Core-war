/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:45:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 21:19:36 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			kill_process(t_proc *proc, t_proc **list)
{
	t_proc	*tmp;

	tmp = *list;
	if (tmp == proc)
		tmp->alive = -1;
	else
	{
		while (proc->next != proc && tmp->next != NULL)
			tmp = tmp->next;
		tmp->alive = -1;
	}
}

int				someone_is_alive(t_proc *list)
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

static void		check_lives2(t_vm *vm, t_proc **list, int last_player)
{
	if (someone_is_alive(*list) == 0 && last_player == 0)
	{
		free_list(list);
		ft_putendl("Tous les joueurs sont morts");
		sleep(30);
		exit(1);
	}
	else if (last_player != 0)
	{
		ft_printf("dernier player : %s\n", vm->tab_champ[last_player - 1].name);
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

void			check_lives(t_vm *vm, t_proc **list)
{
	t_proc	*tmp;
	int		last_player;

	tmp = *list;
	last_player = 0;
	while (tmp != NULL)
	{
		if (tmp->live_period == 0 && tmp->alive >= 0)
		{
			tmp->alive = -1;
			if (tmp->instruction == 1)
				last_player = tmp->id;
		}
		else
			tmp->live_period = 0;
		tmp = tmp->next;
	}
	check_lives2(vm, list, last_player);
}


