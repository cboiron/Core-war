/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:25:42 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/20 01:02:05 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_octetcodage()
{
	//regarder par rapport aux param suivants
}

static void		write_opcode(char *name, int fd)
{
	t_op *tab_op;
	int i;
	int nbr;

	i = -1;
	tab_op = get_ops();
	while (ft_strcmp(tab_op[++i].name, name) != 0);
	write(fd, &tab_op[i].opcode, sizeof(tab_op[i].opcode) / 4);
}

static void	    write_body(int fd, t_asm *env)
{
	char **split;
	int i;

	i = 0;
	split = ft_strsplit(env->buff->content, ' ');
	if (split[i][ft_strlen(split[0]) - 1] == LABEL_CHAR)
		i++;
	write_opcode(split[i], fd);
	write_octetcodage();////////////je suis la
}

void			ft_write_out(t_asm *env)
{
	env->fd = open(env->champ_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	env->header->prog_size = reverse_bits(env->header->prog_size) << 24;
	write(fd, env->header, sizeof(t_header));
	ft_printf("test : %s\n",env->buff->content);
	write_body(fd, env);
	close(fd);
}
