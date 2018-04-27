/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 04:45:35 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/27 04:39:15 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc	*fork_proc(t_proc *father, int adress)
{
	t_proc	*son;
	int		i;

	i = 0;
	son = ft_memalloc(sizeof(t_proc));
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
	son->next = NULL;
	son->pc = adress;
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

	proc->pc++;
	adress = get_dir(vm, &(proc->pc), 12);
	//adress -= 3;
	printf("adress %d\n", adress);
	if (proc->instruction == 12)
	{
		//ft_putendl("je fais un fork");
		add_to_list(list, (fork_proc(proc, adress % IDX_MOD)));
	}
	else if (proc->instruction == 15)
	{
		//ft_putendl("je fais un lfork");
		add_to_list(list, (fork_proc(proc, adress)));
	}
}
