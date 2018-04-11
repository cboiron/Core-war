/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 06:32:05 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/11 06:48:40 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_instruction(t_vm *vm, t_proc *proc)
{
	int	instruction;

	instruction = vm->arena[proc->pc];
	if (instruction > 0 && instruction < 17)
	{
		proc->instruction = instruction;
		if (instruction == 1 || instruction == 4 || instruction == 5 ||
				instruction == 13)
			proc->cycle_to_wait = 10;
		else if (instruction == 16)
			proc->cycle_to_wait = 2;
		else if (instruction == 2 || instruction == 3)
			proc->cycle_to_wait = 5;
		else if (instruction == 6 || instruction == 7 || instruction == 8)
			proc->cycle_to_wait = 6;
		else if (instruction == 9)
			proc->cycle_to_wait = 20;
		else if (instruction == 10 || instruction == 11)
			proc->cycle_to_wait = 25;
		else if (instruction == 12)
			proc->cycle_to_wait = 800;
		else if (instruction == 14)
			proc->cycle_to_wait = 50;
		else if (instruction == 15)
			proc->cycle_to_wait = 1000;
	}
	else
		proc->pc++;
}
