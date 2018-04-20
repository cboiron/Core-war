/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 23:41:45 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/21 01:21:44 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_in_memory(t_vm *vm, int value, int adress, int pc)
{
	printf("val %d\n",value);
	adress = adress % IDX_MOD;
	vm->arena[adress] = value >> 24;
	vm->arena[adress + 1] = value >> 16 & 255;
	vm->arena[adress + 2] = value >> 8 & 255;
	vm->arena[adress + 3] = value & 255;
}
