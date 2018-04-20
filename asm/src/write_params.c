/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:46:23 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/21 00:51:05 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_params(int fd, char *split)
{
	char **splited;
	int i;
	int j;
	unsigned int to_write;

	splited = ft_strsplit(split, SEPARATOR_CHAR);
	i = -1;
	j = tab_len(splited);
	to_write = 0;
	while (j++ < 3)
		write (fd, &to_write, T_REG);
	while (++i < tab_len(splited))
	{
		if (check_param(splited[i]) == 1)
		{
			ft_printf("reg : %s\n", splited[i]);
			to_write = ft_atoi(ft_strsub(splited[i], 1,
										 ft_strlen(splited[i])));
			write(fd, &to_write, T_REG);
		}
		else if (check_param(splited[i]) == 3)
		{
			ft_printf("dir : %s\n", splited[i]);
			to_write = ft_atoi(ft_strsub(splited[i], 1,
										 ft_strlen(splited[i])));
			write(fd, &to_write, T_IND);
		}
		else
			if ((search_char(splited[i], LABEL_CHAR)) == -1)
			{
				ft_printf("indir : %s\n", splited[i]);
				to_write = ft_atoi(ft_strsub(splited[i], 1,
											 ft_strlen(splited[i])));
				write(fd, &to_write, T_DIR);
			}
			else
				ft_printf("label : %s\n", splited[i]);
		ft_printf("to_write : %d\n", to_write);
//		write(fd, &to_write, sizeof(to_write));
		to_write = 0;
	}
}
