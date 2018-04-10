/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 00:38:28 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/07 04:02:39 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "op.h"
typedef struct		s_proc
{
	int				carry;
	int				pc;
	int				reg[REG_NUMBER];
	int				instruction;
	int				cycle_to_wait;
	int				live_period;
	int				id;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_champ
{
	int				id;
	char			*name;
	char			comment[COMMENT_LENGTH];
	int				magic_number;
	int				weight;
	char			*prog;

}					t_champ;

typedef struct		s_vm
{
	int				fd;
	int				dump_cycle;
	t_champ			tab_champ[MAX_PLAYERS];
	int				nbr_next;
	unsigned char	arena[MEM_SIZE];
	int				cycle;
	int				cycle_to_die;
}					t_vm;

#endif
