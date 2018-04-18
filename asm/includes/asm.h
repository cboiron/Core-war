/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:11:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/18 19:52:13 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include "op.h"
# include "../../libft/includes/libft.h"
# include <stdint.h>

# define OUTPUT_EXT "cor"
# define INPUT_EXT 's'
# define REG_DIGIT "0123456"

/*
** format : 1 -> only label
** format : 2 -> only instruction
** format : 3 -> both
*/

typedef struct			s_towrite
{
	unsigned char		*content;
	struct s_towrite	*next;
}						t_towrite;

typedef struct			s_parsing
{
	char				*content;
	int					format;
	struct s_parsing	*next;
}						t_parsing;

typedef struct			s_asm
{
	char				*champ_name;
	t_parsing  			*buff;
	t_towrite			*buff_write;
	t_header			*header;
	int					verif_name;
	int					verif_com;
}						t_asm;

/*
** line.c
*/
char					*rm_comment(char *line);
char					*rm_comment_header(char *line);
int						is_header(char *line, char *macro);
/*
** parsing.c
*/
void					parsing(char *file, t_asm *env);
/*
** utilities.c
*/
int						search_char(char *line, char c);
int						ft_is_number(char *line, int begin);
int						isreg(char *line);
int						isdir(char *line);
int						isindir(char *line);
/*
** dump_header.c
*/
int						dump_header(char *line, t_asm *env, char *macro);
/*
** check_op.c
*/
int						is_label_only(char *line);
int						check_instruction(char *line);
int						check_lab_and_instru(char *line);
/*
** add_op.c
*/
void					add_label(char *line, t_parsing **buff);
void					add_instru(char *line, t_parsing **buff);
void					add_lab_and_instru(char *line, t_parsing **buff);
/*
** de op1.c à op4.c
*/
int						ft_live(char *line);
int						ft_ld(char *line);
int						ft_st(char *line);
int						ft_add(char *line);
int						ft_sub(char *line);
int						ft_and(char *line);
int						ft_or(char *line);
int						ft_xor(char *line);
int						ft_zjmp(char *line);
int						ft_ldi(char *line);
int						ft_sti(char *line);
int						ft_fork(char *line);
int						ft_lld(char *line);
int						ft_lldi(char *line);
int						ft_lfork(char *line);
int						ft_aff(char *line);
/*
** utilities2.c
*/
int						tab_len(char **tab);
uint64_t				reverse_bits(uint64_t val);
/*
** writend.c
*/
void					ft_write_out(t_asm *env);
#endif
