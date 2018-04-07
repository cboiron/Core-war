/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:41:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/07 04:06:41 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_param_type(t_vm *vm, int *i, int op_code)
{
	int	octet;
	int j;

	(*i)++;
	octet = vm->arena[*i];
	octet = octet >> 2;
	while (octet)
	{
		//printf("\n octect = %x \n", octet);
		if ((octet & 1) && !(octet & 2))
			//ft_putendl("reg");
			get_reg(vm, i);
		else if (octet & 2)
			//ft_putendl("direct");
			get_dir(vm, i, op_code);
		else if (octet & 3)
			//ft_putendl("index");
			get_ind(vm , i);
		octet = octet >> 2;
	}
	(*i)++;
}

void	read_op_code(t_vm *vm, int *i)
{
	static void (*opc[17])(t_vm *vm, int *i) = {NULL, &live, &ld, &st, &add,
		&sub, &and, &or, &xor, &zjmp, &ldi, &sti, &forkk, &lld, &lldi, &lfork,
		&aff};
	int		j;

	j = 1;
	while (j <= 16)
	{
		if (vm->arena[*i] == j)
		{
		//	printf(" i   = %d  \n", *i);
		//	ft_putendl("op code");
		//	ft_putnbr(j);
		//	ft_putendl("-------------------");
			//printf("op code  = %d  \n", j);
			if (j == 2 || j == 3 || j == 4 || j == 5 || j == 6 || j == 7
					|| j == 8 || j == 10 || j == 11 || j == 13 || j == 14 ||
					j == 16)
				get_param_type(vm, i, j);
			opc[j](vm, i);
		}
		j++;
	}
}

void	init_proc(t_proc **list, t_vm *vm)
{
	int	i;

	i = 0;
	while (i < vm->nbr_next)
	{
		add_process(list, new_process(vm->tab_champ[i]));
		printf("processus cree avec l'id %d\n", vm->tab_champ[i].id);
		i++;
	}
}

void	play(t_vm *vm)
{
	int		cycle;
	t_proc	*list;

	init_proc(&list, vm);
	cycle = 0;
	while (cycle < 5000)
	{
		read_op_code(vm, &cycle);
		cycle++;
	}
	/*
	 * while (1)
	 * {
	 *	vm->cycle++;
	 * }
	 * */
}
