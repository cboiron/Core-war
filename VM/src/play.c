/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:41:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/14 16:46:39 by cboiron          ###   ########.fr       */
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

void	read_op_code(t_vm *vm, int *i, int instruction)
{
	static void (*opc[17])(t_vm *vm, int *i) = {NULL, &live, &ld, &st, &add,
		&sub, &and, &or, &xor, &zjmp, &ldi, &sti, &forkk, &lld, &lldi, &lfork,
		&aff};
	int		j;

	j = 1;
	while (j <= 16)
	{
		if (instruction == j)
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
			//printf(" i avant   = %d  \n", *i);
			opc[j](vm, i);
			//printf(" i apres  = %d  \n", *i);
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
		add_process(list, new_process(vm->tab_champ[i], i, vm));
		printf("processus cree avec l'id %d\n", vm->tab_champ[i].id);
		i++;
	}
	//ft_putendl("nb process");
	//ft_putnbr(i);
	//ft_putendl("nb joueurs");
	//ft_putnbr(vm->nbr_next);
}

void	parse_list(t_proc **list, t_vm *vm)
{
	t_proc	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		//printf("pc debut de la liste de process =  %d\n", tmp->pc);
		if (tmp->cycle_to_wait == 0)
		{
			read_op_code(vm, &(tmp->pc), tmp->instruction);
		//printf("pc sortie de la liste de read_op_code =  %d\n", tmp->pc);
			tmp->instruction = 0;
			tmp->cycle_to_wait = -1;
		}
		else if (tmp->cycle_to_wait > 0)
			tmp->cycle_to_wait--;
		else if (tmp->instruction == 0)
			get_instruction(vm, tmp);
		//printf("num instruction : %d\n", tmp->instruction);
		//printf("wait : %d\n", tmp->cycle_to_wait);
		//printf("pc = %d\n", tmp->pc);
		/*
		ft_putendl("id = ");
		ft_putnbr(tmp->id);
		ft_putendl("");
		ft_putendl("pc = ");
		ft_putnbr(tmp->pc);
		ft_putendl("");
		*/
		//ft_putnbr(tmp->cycle_to_wait);
			tmp = tmp->next;
		i++;
	}
}

void	play(t_vm *vm)
{
	int		cycle;
	t_proc	*list;

	list = NULL;
	init_proc(&list, vm);
	parse_list(&list, vm);
	cycle = 0;

	while (cycle < 4090)
	{
		parse_list(&list, vm);
		//read_op_code(vm, &cycle);
		if (vm->cycle_before_checking == 0)
			check_lives(vm, &list);
		vm->cycle_before_checking--;
		cycle++;
	}
}
