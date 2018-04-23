/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:46:23 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/24 00:20:18 by abrichar         ###   ########.fr       */
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

static void	write_dir(char *dir, int fd, t_op actual)
{
	unsigned int to_write;

	if ((search_char(dir, LABEL_CHAR)) == -1)
	{
		ft_printf("dir : %s\n", dir);
		to_write = ft_atoi(ft_strsub(dir, 1,
									 ft_strlen(dir)));
		if (actual.opcode == 9 || actual.opcode == 12 || actual.opcode == 15 ||
			actual.opcode == 14 || actual.opcode == 10 || actual.opcode == 11)
			ft_putshort_fd(to_write, fd);
		else
			ft_putint_fd(to_write, fd);
	}
	else
		ft_printf("label : %s\n", dir);
}

void	write_params(int fd, char *split, t_op actual)
{
	char **splited;
	int i;
	unsigned int to_write;

	splited = ft_strsplit(split, SEPARATOR_CHAR);
	i = -1;
	while (++i < tab_len(splited))
	{
		to_write = 0;
		if (check_param(splited[i]) == REG_CODE)
		{
			ft_printf("reg : %s\n", splited[i]);
			to_write = (unsigned int)ft_atoi(ft_strsub(splited[i], 1,
										 ft_strlen(splited[i])));
			write(fd, &to_write, 1);
		}
		else if (check_param(splited[i]) == IND_CODE)
		{
			ft_printf("ind : %s\n", splited[i]);
			to_write = ft_atoi(ft_strsub(splited[i], 0,
										 ft_strlen(splited[i])));
			ft_putshort_fd(to_write, fd);
		}
		else
			write_dir(splited[i], fd, actual);
	}
}
