/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:27:37 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/02 04:58:58 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_vm *vm, t_proc *proc)
{
	int	dir;
	int	pc;

	ft_putendl("je fais un zjmp");
	proc->pc++;
	pc = proc->pc;
	printf("pc = %d\n", pc);
	dir = (short)get_dir(vm, &pc, 9);
	printf("adress = %d\n", dir);
	if (dir < 0)
		dir %= -IDX_MOD;
	else
		dir %= IDX_MOD;
	printf("adress modulee = %d\n", dir);
	printf("pc = %d\n", pc);
	//printf("pc = %d\n", proc->pc);
	//printf("adress after check = %d\n", dir);
	if (proc->carry == 1)
	{
		proc->pc = mod(dir + pc, MEM_SIZE);
		printf("pc final = %d\n", proc->pc);
		return ;
	}
	else
		proc->pc = pc;
	//ft_putendl("je fais un zjmp");
	//si carry == 1
	//ALORS
	//la prochaine instruction sera a l'adresse de vm->arena[*i + 2]
}
