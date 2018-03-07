/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 07:28:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/03/07 01:29:16 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "stdio.h"

void	dump_arena(unsigned char *arena)
{
	int				i;
	int				mem;

	mem = 64;
	i = 1;
	printf("0x0000 : ");
	while (i < MEM_SIZE + 1)
	{
		printf("%02x ", arena[i]);
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


void	create_arena()
{
	unsigned char	arena[MEM_SIZE];
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		arena[i] = 0;
		i++;
	}
	dump_arena(arena);
}
