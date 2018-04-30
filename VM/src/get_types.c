/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:01:26 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/30 11:30:27 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_types(unsigned char octet, t_proc *proc)
{
	unsigned char	param1;
	unsigned char	param2;
	unsigned char	param3;

	printf("octet = %d\n", octet);
	param1 = octet >> 6;
	param2 = octet << 2;
	param2 = param2 >> 6;
	param3 = octet << 4;
	param3 = param3 >> 6;
	proc->parametres_types[0] = param1;
	proc->parametres_types[1] = param2;
	proc->parametres_types[2] = param3;
	printf("param1 = %d\n", param1);
	printf("param2 = %d\n", param2);
	printf("param3 = %d\n", param3);
}
