/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:41:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 15:14:37 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			has_ocp(int j)
{
	if (j == 2 || j == 3 || j == 4 || j == 5 || j == 6 || j == 7
			|| j == 8 || j == 10 || j == 11 || j == 13 || j == 14 ||
			j == 16)
		return (1);
	return (0);
}

void			read_op_code(t_vm *vm, t_proc *proc, int instruction,
		t_proc **list)
{
	static void	(*opc[17])(t_vm *vm, t_proc *proc) = {NULL, &live, &ld, &st,
		&add, &sub, &and, &or, &xor, &zjmp, &ldi, &sti, NULL, &lld, &ldi, NULL,
		&aff};
	int		j;

	PARAM1 = 0;
	PARAM2 = 0;
	PARAM3 = 0;
	j = 1;
	while (j <= 16)
	{
		if (instruction == j)
		{
			proc->save_pc = proc->pc;
			if (j == 12 || j == 15)
			{
				forkk(vm, proc, list);
				return ;
			}
			if (has_ocp(j))
			{
				if (get_types((unsigned char)vm->arena[mod(proc->pc + 1,
							MEM_SIZE)], proc) == 0)
				{
					proc->pc += 2;
					return ;
				}
			}
			opc[j](vm, proc);
		}
		j++;
	}
}

void		init_proc(t_proc **list, t_vm *vm)
{
	int		i;

	i = 0;
	while (i < vm->nbr_next)
	{
		add_process(list, new_process(vm->tab_champ[i], i, vm));
		i++;
	}
}

void		parse_list(t_proc **list, t_vm *vm)
{
	t_proc	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		if (tmp->cycle_to_wait == 0 && tmp->alive >= 0)
		{
			read_op_code(vm, tmp, tmp->instruction, list);
			tmp->instruction = 0;
			tmp->cycle_to_wait = -1;
		}
		else if (tmp->cycle_to_wait > 0)
			tmp->cycle_to_wait--;
		else if (tmp->instruction == 0)
			get_instruction(vm, tmp);
			tmp = tmp->next;
		i++;
	}
}

void		play(t_vm *vm)
{
	int		cycle;
	t_proc	*list;

	list = NULL;
	cycle = 0;
	init_proc(&list, vm);
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
		printf("c'est le %d eme cycle\n", cycle);
		cycle++;
	}
}
