/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 04:45:35 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 15:05:36 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*fork_proc(t_proc *father, int adress)
{
	t_proc	*son;
	int		i;

	son = NULL;
	i = 0;
	son = (t_proc*)ft_memalloc(sizeof(t_proc));
	son->carry = father->carry;
	while (i < REG_NUMBER)
	{
		son->reg[i] = father->reg[i];
		i++;
	}
	son->live_period = father->live_period;
	son->id = father->id;
	son->cycle_to_wait = 0;
	son->instruction = 0;
	son->alive = 1;
	son->next = NULL;
	son->pc = mod(adress, MEM_SIZE);
	return (son);
}

void	add_to_list(t_proc **list, t_proc *new_proc)
{
	new_proc->next = (*list);
	(*list) = new_proc;
}

void	forkk(t_vm *vm, t_proc *proc, t_proc **list)
{
	int	adress;
	int	pc;

	proc->pc++;
	pc = proc->pc;
	adress = 0;
	adress = (short)get_dir(vm, &pc, 12);
	if (proc->instruction == 12)
		add_to_list(list, (fork_proc(proc, proc->save_pc +
						(adress % IDX_MOD))));
	else if (proc->instruction == 15)
		add_to_list(list, (fork_proc(proc, proc->save_pc + adress)));
	proc->pc = pc;
}
