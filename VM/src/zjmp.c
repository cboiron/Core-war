/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:27:37 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/27 04:48:27 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_vm *vm, t_proc *proc)
{
	int	dir;

	ft_putendl("je fais un zjmp");
	proc->pc++;
	dir = get_dir(vm, &(proc->pc), 9);
	//printf("adress = %d\n", dir);
	//printf("pc = %d\n", proc->pc);
	//dir %= IDX_MOD;
	if (dir >> 15)
		dir -= 65536;
	//printf("adress neg = %d\n", dir);
	if (dir < 0)
	{
		dir %= -IDX_MOD;
		dir += MEM_SIZE;
	}
	else
		dir %= IDX_MOD;
	//printf("adress after check = %d\n", dir);
	if (proc->carry == 1)
	{
		proc->pc += (dir);
		proc->pc %= MEM_SIZE;
	}
	//ft_putendl("je fais un zjmp");
	//printf("pc final= %d\n", proc->pc);
	//si carry == 1
	//ALORS
	//la prochaine instruction sera a l'adresse de vm->arena[*i + 2]
}
