/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 07:43:36 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/14 21:30:06 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_reg(t_vm *vm, int *i)
{
	(*i)++;
	//ft_putendl(" + 1");
}

void	get_ind(t_vm *vm, int *i)
{
	{
	(*i) += 2;
//	ft_putendl(" + 2");
	}
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
		dir += vm->arena[(*i)];
		dir <<= 8;
		dir += vm->arena[(*i) + 1];
		(*i) += 2;
//		ft_putendl(" + 2");
	}
	else
	{
		while (j < 4)
		{
			dir += vm->arena[j + (*i)];
	//		ft_printf("dir = %d\n", dir);
			if (j != 3)
				dir <<= 8;
			j++;
		}
		(*i) += 4;
	}
	ft_printf("dir final = %d\n", dir);
	return (dir);
}
