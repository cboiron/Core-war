/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 23:41:45 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/28 17:34:36 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_in_memory(t_vm *vm, int value, int adress)
{
	printf("val %d\n",value);
	printf("adress %d\n", adress);
	/*
	printf("adress after %d\n", adress);
	*/
	vm->arena[mod(adress, MEM_SIZE)] = value >> 24;
	vm->arena[mod(adress + 1, MEM_SIZE)] = value >> 16 & 255;
	vm->arena[mod(adress + 2, MEM_SIZE)] = value >> 8 & 255;
	vm->arena[mod(adress + 3, MEM_SIZE)] = value & 255;
}
