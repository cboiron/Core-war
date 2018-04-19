/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:25:42 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/19 17:06:43 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*static void	    write_file(int fd, t_asm *env)
{
	write(fd, &env->magic, sizeof(env->magic));
	while(env->buff_write->next)
	{
		ft_putstr("je passe la\n");
		env->buff_write = env->buff_write->next;
		write(fd, env->buff_write->content, sizeof(env->buff_write->content));
		}
}*/

void			ft_write_out(t_asm *env)
{
	int			fd;

	fd = open(env->champ_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
//	write_file(fd, env);
	ft_printf("size : %d\n",env->header->prog_size);
	write(fd, &env->header->magic, sizeof(env->header->magic));
	write(fd, &env->header->prog_name, sizeof(env->header->prog_name));
	write(fd, &env->header->prog_size, sizeof(env->header->prog_size));
	write(fd, &env->header->comment, sizeof(env->header->comment));
//	write_body(fd, env);
	close(fd);
}
