/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:11:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/21 23:29:10 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include "op.h"
# include "../../libft/includes/libft.h"
# include <stdint.h>

# define OP_COUNT 17
# define OUTPUT_EXT "cor"
# define INPUT_EXT 's'
# define REG_DIGIT "0123456"
# define USAGE "usage: ./asm <fichier_source.s> \n"
# define ERR_OPEN "Erreur 01 : Erreur à l'ouverture du fichier."
# define ERR_CLOSE "Erreur 02 : Erreur à la fermeture du fichier."
# define ERR_SYNTAX "Erreur 03 - Ligne non conforme."
# define ERR_NAME "Erreur 04 : Erreur au nom."
# define ERR_COM "Erreur 05 : Erreur au commentaire."
# define ERR_SIZE "Erreur 06 : champion trop grand."
# define ERR_ARG "Erreur 07 : Argument non valide."
# define ERR_NBR_ARG "Erreur 08 : Pas assez d'argument."


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
	unsigned int		size;
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
	int					fd;
}						t_asm;

/*
** main.c
*/
void					msg_error(char *msg, int index);
/*
** prog_size.c
*/
void					verif_size(char *line, t_asm *env);
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
void					dump_header(char *line, t_asm *env, char *macro, int index);
/*
** check_op.c
*/
int						is_label_only(char *line);
int						check_instruction(char *line, int index);
int						check_lab_and_instru(char *line, int index);
/*
** add_op.c
*/
void					add_label(char *line, t_parsing **buff);
void					add_instru(char *line, t_parsing **buff);
void					add_lab_and_instru(char *line, t_parsing **buff);
unsigned int			size_to_add()
/*
** op.c
*/
t_op					*get_ops();
t_op					*get_op(int opcode);
/*
** de op1.c à op4.c
*/
int						ft_live(char *line, int index);
int						ft_ld(char *line, int index);
int						ft_st(char *line, int index);
int						ft_add(char *line, int index);
int						ft_sub(char *line, int index);
int						ft_and(char *line, int index);
int						ft_or(char *line, int index);
int						ft_xor(char *line, int index);
int						ft_zjmp(char *line, int index);
int						ft_ldi(char *line, int index);
int						ft_sti(char *line, int index);
int						ft_fork(char *line, int index);
int						ft_lld(char *line, int index);
int						ft_lldi(char *line, int index);
int						ft_lfork(char *line, int index);
int						ft_aff(char *line, int index);
/*
** utilities2.c
*/
int						check_param(char *param);
int						tab_len(char **tab);
uint64_t				reverse_bits(uint64_t val);
/*
** writend.c & write_params.c
*/
void					write_out(t_asm *env);
void					write_params(int fd, char *split, t_op actual);
#endif
