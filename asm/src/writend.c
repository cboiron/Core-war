/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:25:42 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/24 12:56:20 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned int	write_octetcodage(t_op actual, char *arg)
{
	char **splited;
	unsigned int param1;
	unsigned int param2;
	unsigned int param3;

	param1 = 0;
	param2 = 0;
	param3 = 0;
	splited = ft_strsplit(arg, SEPARATOR_CHAR);
	clear_split(splited);
	if (actual.opcode != 1 && actual.opcode != 9 && actual.opcode != 12
		&& actual.opcode != 15)
	{
		if (actual.nb_arg >= 1)
			param1 = check_param(splited[0]) << 6;
		if (actual.nb_arg >= 2)
			param2 = check_param(splited[1]) << 4;
		if (actual.nb_arg == 3)
			param3 = check_param(splited[2]) << 2;
		ft_printf("testing\n");
	}
    return(param1 + param2 + param3);
}

t_op		find_opcode(char *name)
{
	t_op *tab_op;
	int i;

	i = -1;
	tab_op = get_ops();
	while (ft_strcmp(tab_op[++i].name, name) != 0);
	return (tab_op[i]);
}
static void    write_body(t_asm *env)
{
	char	**split;
	int		i;
	t_op	actual;
	unsigned int to_write;

	while (env->buff)
	{
		while (env->buff->label == 1 && env->buff->next)
			env->buff = env->buff->next;
		i = 0;
		split = ft_strsplit(env->buff->content, ' ');
		clear_split(split);
		if (split[i][ft_strlen(split[i]) - 1] == LABEL_CHAR)
			i++;
		if (split[i])
		{
			actual = find_opcode(split[i++]);
			write(env->fd, &actual.opcode, sizeof(int) / 4);
			to_write = write_octetcodage(actual, split[i]);
			if (to_write != 0)
				write(env->fd, &to_write, sizeof(int) / 4);
			write_params(env, split[i], actual);
		}
		env->buff = env->buff->next;
	}
}

void			write_out(t_asm *env)
{
	env->fd = open(env->champ_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	env->header->prog_size = reverse_bits(env->header->prog_size) << 24;
	write(env->fd, env->header, sizeof(t_header));
	write_body(env);
	close(env->fd);
}
