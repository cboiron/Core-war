/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 05:52:11 by cboiron           #+#    #+#             */
/*   Updated: 2018/03/14 17:36:34 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void load_champ_to(t_vm *vm, t_champ champ, int memory_index)
{
	int	index;

	index = 0;
	//ft_putnbr(memory_index);
	//ft_putendl("memory");
	/*
	ft_putendl("poids = ");
	ft_putnbr(champ.weight);
	ft_putendl("---------------------- ");
	while (index < champ.weight)
	{
		//ft_putnbr(index);
		//ft_putendl("");
		vm->arena[index + memory_index] = (unsigned char)champ.prog[index];
		//dump_arena(vm);
		index++;
	}
	*/
//	dump_arena(vm);
}

void	load_champs(t_vm *vm)
{
	int	space_bt_champs;
	int	num_players;
	int space;

	num_players = 1;
	space_bt_champs = MEM_SIZE / vm->nbr_next;
	if (vm->nbr_next == 1)
		space_bt_champs = 0;
	space = space_bt_champs;
	//while (vm->tab_champ[num_players] != NULL)
	{
		load_champ_to(vm, vm->tab_champ[0], space);
		space += space_bt_champs;
		num_players++;
	}
}
