/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:41:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/03/25 05:16:48 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_op_code(t_vm *vm, int *i)
{
	static void (*opc[16])(t_vm *vm, int *i) = {NULL, &live, &ld, &st, &add,
		&sub, &or, &xor, &zjmp, &ldi, &sti, &forkk, &lld, &lldi, &lfork,
		&forkk};
	int		j;

	j = 1;
	while (j <= 16)
	{
		if (vm->arena[*i] == j)
		{
			//printf("j = %d | \n", j);
			opc[j](vm, i);
		}
		j++;
	}
}

void	play(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		read_op_code(vm, &i);
		i++;
	}
	/*
	 * while (1)
	 * {
	 *	vm->cycle++;
	 * }
	 * */
}
