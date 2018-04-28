/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:41:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/28 11:10:51 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reverse_params(t_proc *proc)
{
	int	tmp1;

	tmp1 = proc->parametres_types[2];
	proc->parametres_types[2] = proc->parametres_types[0];
	proc->parametres_types[0] = tmp1;
}

void	get_param_type(t_vm *vm, int i, t_proc *proc)
{
	int	octet;
	int	index_param;

	i++;
	index_param = 0;
	//printf(" i   = %d  \n", (*i) % MEM_SIZE);
	//printf(" op code   = %d  \n", op_code);
	octet = vm->arena[i % MEM_SIZE];
	octet = octet >> 2;
	while (octet)
	{
		if ((octet & 1) && !(octet & 2))
			proc->parametres_types[index_param] = REG;
		else if (octet & 2)
			proc->parametres_types[index_param] = DIRECT;
		else if (octet & 3)
			proc->parametres_types[index_param] = INDIRECT;
		index_param++;
		octet = octet >> 2;
	}
	reverse_params(proc);
	i++;
}

void	read_op_code(t_vm *vm, t_proc *proc, int instruction, t_proc **list)
{
	static void (*opc[17])(t_vm *vm, t_proc *proc) = {NULL, &live, &ld, &st, &add,
		&sub, &and, &or, &xor, &zjmp, &ldi, &sti, NULL, &lld, &ldi, NULL,
		&aff};
	int		j;

	proc->parametres_types[0] = 0;
	proc->parametres_types[1] = 0;
	proc->parametres_types[2] = 0;
	j = 1;
	while (j <= 16)
	{
		if (instruction == j)
		{
		//	printf(" i   = %d  \n", *i);
		//	ft_putendl("op code");
		//	ft_putnbr(j);
		//	ft_putendl("-------------------")
			//printf("op code  = %d  \n", j);
			proc->save_pc = proc->pc;
			if (j == 12 || j == 15)
			{
				forkk(vm, proc, list);
				return ;
			}
			if (j == 2 || j == 3 || j == 4 || j == 5 || j == 6 || j == 7
					|| j == 8 || j == 10 || j == 11 || j == 13 || j == 14 ||
					j == 16)
				get_param_type(vm, proc->pc, proc);
			//printf(" i avant   = %d  \n", proc->pc);
			//printf(" op code   = %d  \n", vm->arena[proc->pc]);
			opc[j](vm, proc);
			//printf(" i apres  = %d  \n", proc->pc);
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
		//printf("processus cree avec l'id %d\n", vm->tab_champ[i].id);
		i++;
	}
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
			read_op_code(vm, tmp, tmp->instruction, list);
		//printf("pc sortie de la liste de read_op_code =  %d\n", tmp->pc);
			tmp->instruction = 0;
			tmp->cycle_to_wait = -1;
		}
		else if (tmp->cycle_to_wait > 0)
			tmp->cycle_to_wait--;
		else if (tmp->instruction == 0)
			get_instruction(vm, tmp);
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
	cycle = 0;
	init_proc(&list, vm);
//	parse_list(&list, vm);
	while (42)
	{
		parse_list(&list, vm);
		if (vm->cycle_before_checking == 0)
			check_lives(vm, &list);
		vm->cycle_before_checking--;
		if (cycle == vm->dump_cycle)
		{
			dump_arena(vm);
			break ;
		}
		//printf("c'est le %d eme cycle\n", cycle);
		cycle++;
	}
	//dump_arena(vm);
}
