/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:01:26 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 03:41:05 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	check_types(t_proc *proc)
{
	if (OP == 2 && ((PARAM1 != DIRECT && PARAM1 != INDIRECT) ||
				PARAM2 != REG ))
		return (0);
	if (OP == 3 && ((PARAM1 != REG) || (PARAM2 != INDIRECT && PARAM2 != REG)))
		return (0);
	if (OP == 4 || OP == 5)
		if (PARAM1 != REG || PARAM2 != REG || PARAM3 != REG)
			return (0);
	if (OP == 6 || OP == 7 || OP == 8)
		if (PARAM1 == 0 || PARAM2 == 0 || PARAM3 != REG)
			return (0);
	if ((OP == 10 || OP == 14) &&
			((PARAM1 == 0) || (PARAM2 != DIRECT && PARAM2 != REG)
			 || PARAM3 != REG))
		return (0);
	if (OP == 11 && (PARAM1 != REG || PARAM2 == 0 ||
				(PARAM3 != DIRECT && PARAM3 != REG)))
		return (0);
	if (OP == 13 && ((PARAM1 != DIRECT && PARAM1 != INDIRECT) || PARAM2 != REG))
		return (0);
	if (OP == 16 && (PARAM1 != REG || PARAM2 != 0 || PARAM3 != 0))
		return (0);
	return (1);
}

int	get_types(unsigned char octet, t_proc *proc)
{
	unsigned char	param1;
	unsigned char	param2;
	unsigned char	param3;

	param1 = octet >> 6;
	param2 = octet << 2;
	param2 = param2 >> 6;
	param3 = octet << 4;
	param3 = param3 >> 6;
	proc->parametres_types[0] = param1;
	proc->parametres_types[1] = param2;
	proc->parametres_types[2] = param3;
	printf("param1 type = %d\n", param1);
	printf("param2 type = %d\n", param2);
	printf("param3 type = %d\n", param3);

	return (check_types(proc));
}
