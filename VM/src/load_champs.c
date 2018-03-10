/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 05:52:11 by cboiron           #+#    #+#             */
/*   Updated: 2018/03/10 05:52:21 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	load_champs(t_vm *vm)
{
	int	space_bt_champs;
	int	num_players;

	num_players = 1;
	space_bt_champs = MEM_SIZE / vm->nbr_next;
	if (vm->nbr_next == 1)
		space_bt_champs = 0;
	space = space_bt_champs;
	while (vm->tab_champ[num_players])
	{
		load_champ_to(vm->tab_champ[num_players]->prog, space);
		space += space_bt_champs;
		num_players++;
	}
}
