/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:41:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/03/21 05:16:19 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_op_code(t_vm *vm, int *i)
{
	if (vm->arena[*i] == 1)
		ft_putendl("live");
	else if (vm->arena[*i] == 2)
		ft_putendl("ld");
	else if (vm->arena[*i] == 3)
		ft_putendl("st");
	else if (vm->arena[*i] == 4)
		ft_putendl("add");
	else if (vm->arena[*i] == 5)
		ft_putendl("sub");
	else if (vm->arena[*i] == 6)
		ft_putendl("and");
	else if (vm->arena[*i] == 7)
		ft_putendl("or");
	else if (vm->arena[*i] == 8)
		ft_putendl("xor");
	else if (vm->arena[*i] == 9)
		ft_putendl("zjmp");
	else if (vm->arena[*i] == 10)
		ft_putendl("ldi");
	else if (vm->arena[*i] == 11)
		ft_putendl("sti");
	else if (vm->arena[*i] == 12)
		ft_putendl("fork");
	else if (vm->arena[*i] == 13)
		ft_putendl("lld");
	else if (vm->arena[*i] == 14)
		ft_putendl("lldi");
	else if (vm->arena[*i] == 15)
		ft_putendl("lfork");
	else if (vm->arena[*i] == 16)
		ft_putendl("aff");
	/*{
		printf("i = %d |", i);
		printf("char = %x \n", vm->arena[i]);
	}*/
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
