/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:27:37 by abrichar          #+#    #+#             */
/*   Updated: 2018/03/25 08:28:39 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_vm *vm, int *i)
{
	//si carry == 1
	//ALORS
	//la prochaine instruction sera a l'adresse de vm->arena[*i + 2]
	(*i) += 2;
}
