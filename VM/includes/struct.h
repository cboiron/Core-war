/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 00:38:28 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/03 20:59:29 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define REG 1
# define DIRECT 2
# define INDIRECT 3
# define OP proc->instruction
# define PARAM1 proc->parametres_types[0]
# define PARAM2 proc->parametres_types[1]
# define PARAM3 proc->parametres_types[2]

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
	int				parametres_types[3];
	int				save_pc;
	int				alive;
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
	int				last_check;
	int				cycle_to_die;
	int				cycle_before_checking;
	int				total_lives_period;
}					t_vm;

#endif
