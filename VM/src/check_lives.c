/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:45:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/04 00:18:15 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	print_winner(t_vm *vm, int id_player)
{
	int	i;

	i = 0;
	while (id_player != vm->tab_champ[i].id)
		i++;
	ft_printf("Le vainqueur est le joueur %d: %s !! \n", id_player,
			vm->tab_champ[i].name);
	return (0);
}

static int	someone_is_alive(t_proc *list)
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

static int	check_lives2(t_vm *vm, t_proc **list, int last_player)
{
	if (someone_is_alive(*list) == 0 && last_player == 0)
	{
		free_list(list);
		ft_putendl("Tous les joueurs sont morts");
		return (0);
	}
	else if (last_player != 0)
		return (print_winner(vm, last_player));
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
	return (1);
}

int			check_lives(t_vm *vm, t_proc **list)
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
	return (check_lives2(vm, list, last_player));
}
