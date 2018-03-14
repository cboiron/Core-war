/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 00:38:28 by abrichar          #+#    #+#             */
/*   Updated: 2018/03/14 16:57:10 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_champ
{
	int				num;
	char			*name;
	char			comment[COMMENT_LENGTH];
	int				magic_number;
	int				weight;
	char			*prog;

}					t_champ;

typedef struct		s_vm
{
	int				fd;
	int				nbr_cycle;
	t_champ			tab_champ[MAX_PLAYERS];
	int				nbr_next;
	unsigned char	arena[MEM_SIZE];
}					t_vm;

#endif
