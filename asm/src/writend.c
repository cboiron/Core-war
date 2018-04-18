/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:25:42 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/17 14:55:55 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*static void	write_body(int fd, t_asm *env)
{

}*/

void		ft_write_out(t_asm *env)
{
	int fd;

	ft_printf("test");
	fd = open(env->champ_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	write(fd, &env->magic, sizeof(env->magic));
//	write(fd, env->name, ft_strlen(env->name));
//	write(fd, &env->length, sizeof(env->length));
//	write(fd, env->comment, ft_strlen(env->comment));
//	write_body(fd, env);
	close(fd);
}
