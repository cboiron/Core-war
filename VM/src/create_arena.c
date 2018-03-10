/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 07:28:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/03/08 23:56:45 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_arena(t_vm *vm)
{
	int				i;
	int				mem;

	mem = 64;
	i = 1;
	printf("0x0000 : ");
	while (i < MEM_SIZE + 1)
	{
		printf("%02x ", vm->arena[i]);
		if (i % 64 == 0 && i != MEM_SIZE)
		{
			printf("\n");
			printf("%#06x : ", mem);
			mem += 64;
		}
		i++;
	}
	printf("\n");
}


void	create_arena(t_vm *vm)
{
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->arena[i] = 0;
		i++;
	}
}
