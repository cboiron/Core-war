/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:11:25 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/07 03:59:43 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include "./libft.h"
# include "./op.h"
# include "./struct.h"
# include <stdio.h>
# include <fcntl.h>

/*
** main.c
*/
void	read_champ(t_vm *vm, int number_player);
void	init_vm(t_vm *vm);
int		usage(void);
int		main(int argc, char **argv);
/*
** param.c
*/
int		param_n(t_vm *vm, int number_player, char **av, int *i);
int		ft_isnumber(char *str);
int		get_param(char **av, t_vm *vm, int ac);
/*
** create_arena.c
*/
void	dump_arena(t_vm *vm);
void	create_arena(t_vm *vm);
/*
 ** load_champs.c
 */
void	load_champs(t_vm *vm);

/*
 *instructions_param.c
 */
void	get_reg(t_vm *vm, int *i);
void	get_ind(t_vm *vm, int *i);
void	get_dir(t_vm *vm, int *i, int op_code);
/*
 ** process.c
 */
t_proc	*new_process(t_champ champ);
void	add_process(t_proc **list, t_proc *proc);
void	free_process(t_proc *proc);

void	play(t_vm *vm);

void	live(t_vm *vm, int *i);
void	ld(t_vm *vm, int *i);
void	st(t_vm *vm, int *i);
void	add(t_vm *vm, int *i);
void	sub(t_vm *vm, int *i);
void	and(t_vm *vm, int *i);
void	or(t_vm *vm, int *i);
void	xor(t_vm *vm, int *i);
void	zjmp(t_vm *vm, int *i);
void	ldi(t_vm *vm, int *i);
void	sti(t_vm *vm, int *i);
void	forkk(t_vm *vm, int *i);
void	lld(t_vm *vm, int *i);
void	lldi(t_vm *vm, int *i);
void	lfork(t_vm *vm, int *i);
void	aff(t_vm *vm, int *i);

#endif
