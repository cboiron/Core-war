/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:11:25 by abrichar          #+#    #+#             */
/*   Updated: 2018/03/09 08:02:45 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include "../../libft/includes/libft.h"
# include "./op.h"
# include "./struct.h"
# include <stdio.h>

/*
** main.c
*/
void	read_champ(t_vm *vm, int number_player, int ac);
void	init_vm(t_vm *vm);
int		usage(void);
int		main(int argc, char **argv);
/*
** param.c
*/
int		param_n(t_vm *vm, int number_player, char **av, int *i);
int		ft_isnumber(char *str);
int		get_param(char **av, t_vm *vm);
/*
** create_arena.c
*/
void	dump_arena(t_vm *vm);
void	create_arena(t_vm *vm);

#endif
