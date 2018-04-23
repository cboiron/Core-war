/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:46:23 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/24 01:05:35 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_putint_fd(int n, int fd)
{
	ft_putchar_fd((n >> 24) & 0xff, fd);
	ft_putchar_fd((n >> 16) & 0xff, fd);
	ft_putchar_fd((n >> 8) & 0xff, fd);
	ft_putchar_fd(n & 0xff, fd);
	}

static void	ft_putshort_fd(short n, int fd)
{
	ft_putchar_fd((n >> 8) & 0xff, fd);
	ft_putchar_fd(n & 0xff, fd);
}

static void	write_label(char *dir, int fd, t_asm *env)
{
	unsigned int pos;
	if (fd && env)
		ft_printf("label : %s\n", dir);
	pos = 0;
	if (0)
	{
//récupérer la position actuelle
//chercher à partir du début du buff le label que l'on cherche
//quand trouver, faire une addition en considérant que ma position est negative
//finito
	}
}

static void	write_dir(char *dir, t_asm *env, t_op actual)
{
	unsigned int to_write;

	if ((search_char(dir, LABEL_CHAR)) == -1)
	{
		to_write = ft_atoi(ft_strsub(dir, 1,
									 ft_strlen(dir)));
		if (actual.opcode == 9 || actual.opcode == 12 || actual.opcode == 15 ||
			actual.opcode == 14 || actual.opcode == 10 || actual.opcode == 11)
			ft_putshort_fd(to_write, env->fd);
		else
			ft_putint_fd(to_write, env->fd);
	}
	else
		write_label(dir, env->fd, env);
}

void	write_params(t_asm *env, char *split, t_op actual)
{
	char **splited;
	int i;
	unsigned int to_write;

	splited = ft_strsplit(split, SEPARATOR_CHAR);
	clear_split(splited);
	i = -1;
	while (++i < tab_len(splited))
	{
		to_write = 0;
		if (check_param(splited[i]) == REG_CODE)
		{
			to_write = (unsigned int)ft_atoi(ft_strsub(splited[i], 1,
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
			write_dir(splited[i], env, actual);
	}
}
