/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:11:25 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/03 23:38:11 by abrichar         ###   ########.fr       */
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
int			usage(void);
int			main(int argc, char **argv);
/*
** param.c
*/
int			param_n(t_vm *vm, char **av, int *i, int ac);
int			ft_isnumber(char *str);
int			get_param(char **av, t_vm *vm, int ac);
/*
** create_arena.c
*/
void		dump_arena(t_vm *vm);
void		create_arena(t_vm *vm);
/*
** load_champs.c
*/
void		load_champs(t_vm *vm);
/*
** instructions_param.c
*/
int			get_reg(t_vm *vm, int *i);
int			get_ind(t_vm *vm, int *i);
int			get_dir(t_vm *vm, int *i, int op_code);
/*
** process.c
*/
t_proc		*new_process(t_champ champ, int num_player, t_vm *vm);
void		add_process(t_proc **list, t_proc *proc);
/*
** play.c
*/
void		get_instruction(t_vm *vm, t_proc *proc);
void		play(t_vm *vm);
/*
** check_lives.c
*/
int			check_lives(t_vm *vm, t_proc **list);
/*
** (Instructions).c
*/
void		live(t_vm *vm, t_proc *proc);
void		ld(t_vm *vm, t_proc *proc);
long int	get_value(t_vm *vm, int index);
void		st(t_vm *vm, t_proc *proc);
void		add(t_vm *vm, t_proc *proc);
void		sub(t_vm *vm, t_proc *proc);
void		and(t_vm *vm, t_proc *proc);
void		or(t_vm *vm, t_proc *proc);
void		xor(t_vm *vm, t_proc *proc);
void		zjmp(t_vm *vm, t_proc *proc);
void		ldi(t_vm *vm, t_proc *proc);
void		sti(t_vm *vm, t_proc *proc);
void		forkk(t_vm *vm, t_proc *proc, t_proc **list);
void		lld(t_vm *vm, t_proc *proc);
long int	get_value_2(t_vm *vm, int index);
void		lldi(t_vm *vm, t_proc *proc);
void		lfork(t_vm *vm, t_proc *proc);
void		aff(t_vm *vm, t_proc *proc);
/*
** is_reg.c
*/
int			is_reg(int value);
/*
** mod.c
*/
int			mod(int a, int b);
/*
** write_in_memory.c
*/
void		write_in_memory(t_vm *vm, int value, int adress);
/*
** read_champ.c
*/
void		read_champ(t_vm *vm, int number_player);
/*
** and_or_xor.c
*/
void		param_op(t_vm *vm, t_proc *proc, int *arg);
/*
** get_types.c
*/
int			get_types(unsigned char octet, t_proc *proc);
/*
** free_list.c
*/
void		free_list(t_proc **list);
#endif
