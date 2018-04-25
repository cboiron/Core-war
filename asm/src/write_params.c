/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:46:23 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/26 01:51:14 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned int		write_label2(t_parsing *tmp, char *to_search,
									unsigned int size_to_here, t_asm *env)
{
	unsigned int	pos;
	char			*content;

	pos = 0;
	while (tmp)
	{
		while (tmp->label != 1 && tmp)
			tmp = tmp->next;
		content = ft_strsub(tmp->content, 0, ft_strlen(tmp->content) - 1);
		if (ft_strcmp(content, to_search) == 0)
			break ;
		tmp = tmp->next;
	}
	pos = (tmp->size_to_here - size_to_here);
	tmp = env->buff;
	while (tmp)
	{
		if (tmp->size_to_here == size_to_here)
			break ;
		tmp = tmp->next;
	}
	pos += tmp->size;
	return (pos);
}

static void				write_label(char *dir, t_op actual, t_asm *env,
							unsigned int size_to_here)
{
	unsigned int	pos;
	t_parsing		*tmp;
	char			*to_search;
	unsigned int	max;

	max = -1;
	to_search = ft_strsub(dir, 2, ft_strlen(dir) - 2);
	tmp = env->buff;
	pos = write_label2(tmp, to_search, size_to_here, env);
	if (pos == max)
		pos = 0;
	if (actual.opcode >= 9 && actual.opcode <= 15 && actual.opcode != 13)
		ft_putshort_fd(pos, env->fd);
	else
		ft_putint_fd(pos, env->fd);
}

static void				write_dir(char *dir, t_asm *env, t_op actual,
						unsigned int size_to_here)
{
	int	to_write;

	if ((search_char(dir, LABEL_CHAR)) == -1)
	{
		to_write = ft_atoi(ft_strsub(dir, 1,
									ft_strlen(dir)));
		if (actual.opcode >= 9 && actual.opcode != 13 && actual.opcode <= 15)
			ft_putshort_fd(to_write, env->fd);
		else
			ft_putint_fd(to_write, env->fd);
	}
	else
		write_label(dir, actual, env, size_to_here);
}

void					write_params(t_asm *env, char *split, t_op actual,
					unsigned int size_to_here)
{
	char			**splited;
	int				i;
	int				to_write;

	splited = ft_strsplit(split, SEPARATOR_CHAR);
	clear_split(splited);
	i = -1;
	while (++i < tab_len(splited))
	{
		to_write = 0;
		if (check_param(splited[i]) == REG_CODE)
		{
			to_write = ft_atoi(ft_strsub(splited[i], 1,
										ft_strlen(splited[i])));
			write(env->fd, &to_write, 1);
		}
		else if (check_param(splited[i]) == IND_CODE)
		{
			to_write = ft_atoi(ft_strsub(splited[i], 0,
										ft_strlen(splited[i])));
			ft_putshort_fd(to_write, env->fd);
		}
		else
			write_dir(splited[i], env, actual, size_to_here);
	}
}
