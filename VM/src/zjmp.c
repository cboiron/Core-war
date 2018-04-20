/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:27:37 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/20 23:13:18 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_vm *vm, t_proc *proc)
{
	int	dir;

	ft_putendl("je fais un zjmp");
	proc->pc++;
	dir = get_dir(vm, &(proc->pc), 9);
	if (proc->carry == 1)
		proc->pc = dir % IDX_MOD;
	//si carry == 1
	//ALORS
	//la prochaine instruction sera a l'adresse de vm->arena[*i + 2]
}
