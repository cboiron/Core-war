/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:11:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/11 00:35:01 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include "op.h"
# include "../../libft/includes/libft.h"

# define OUTPUT_EXT "cor"
# define INPUT_EXT 's'

typedef struct	s_asm
{
	char		*champ_name;
	int			verif_name;
	int			verif_com;
}				t_asm;

/*
** line.c
*/
char			*rm_comment_header(char *line, char *macro);
int				is_header(char *line, char *macro);
/*
** parsing.c
*/
void			parsing(char *file, t_asm *env);
/*
** utilities.c
*/
int				search_char(char *line, char c);
#endif
