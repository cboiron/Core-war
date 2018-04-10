/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:11:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/10 00:14:24 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include "op.h"

# define OUTPUT_EXT "cor"
# define INPUT_EXT 's'

typedef struct	s_asm
{
	char		*champ_name;
	int			verif_name;
	int			verif_com;
}				t_asm;

#endif
