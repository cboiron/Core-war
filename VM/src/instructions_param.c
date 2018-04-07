/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 07:43:36 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/07 04:05:19 by cboiron          ###   ########.fr       */
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

void	get_dir(t_vm *vm, int *i, int op_code)
{
	if (op_code == 10 || op_code == 11 || op_code == 14)
	{
		(*i) += 2;
//		ft_putendl(" + 2");
	}
	else
	{
		(*i) += 4;
//		ft_putendl(" + 4");
	}
}
