/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 05:52:11 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 08:54:55 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void load_champ_to(t_vm *vm, t_champ champ, int memory_index)
{
	int	index;

	index = 0;
	while (index < champ.weight && (index + memory_index) < MEM_SIZE )
	{
		vm->arena[index + memory_index] = (unsigned char)champ.prog[index];
		index++;
	}
}

void	load_champs(t_vm *vm)
{
	int	space_bt_champs;
	int	num_players;
	int space;

	num_players = 0;
	space_bt_champs = MEM_SIZE / vm->nbr_next;
	if (vm->nbr_next == 1)
		space_bt_champs = 0;
	space = 0;
	while (num_players < vm->nbr_next)
	{
		load_champ_to(vm, vm->tab_champ[num_players], space);
		space += space_bt_champs;
		num_players++;
	}
}
