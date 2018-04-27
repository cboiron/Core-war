/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 07:43:36 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/27 02:23:00 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_reg(t_vm *vm, int *i)
{
	int	reg;

	reg = 0;
	reg = vm->arena[(*i) % MEM_SIZE];
	(*i)++;
	return (reg);
	//ft_putendl(" + 1");
}

int	get_ind(t_vm *vm, int *i)
{
	int	ind;

	ind = 0;
	ind += vm->arena[(*i) % MEM_SIZE];
	ind <<= 8;
	ind += vm->arena[((*i) + 1) % MEM_SIZE];
	{
		(*i) += 2;
		//	ft_putendl(" + 2");
	}
	return (ind);
}

int	get_dir(t_vm *vm, int *i, int op_code)
{
	int	dir;
	int	j;

	j = 0;
	dir = 0;
	if (op_code == 9 || op_code == 10 || op_code == 11 || op_code == 12 ||
			op_code == 14 || op_code == 15)
	{
		dir += vm->arena[(*i) % MEM_SIZE];
		dir <<= 8;
		dir += vm->arena[((*i) + 1) % MEM_SIZE];
		(*i) += 2;
		//		ft_putendl(" + 2");
	}
	else
	{
		while (j < 4)
		{
			dir += vm->arena[(j + (*i)) % MEM_SIZE];
			//		ft_printf("dir = %d\n", dir);
			if (j != 3)
				dir <<= 8;
			j++;
		}
		(*i) += 4;
	}
	//ft_printf("dir final = %d\n", dir);
	return (dir);
}
