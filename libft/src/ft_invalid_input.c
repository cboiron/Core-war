/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <ardurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:55:52 by ardurand          #+#    #+#             */
/*   Updated: 2017/12/13 15:00:39 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		with_width_invalid(char c, t_printf *elem)
{
	int count;

	count = elem->width - 1;
	if (elem->flag_minus)
	{
		ft_putchar(c);
		while (count-- > 0)
			ft_putchar(' ');
	}
	else if (elem->flag_zero)
	{
		while (count-- > 0)
			ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		while (count-- > 0)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (elem->width);
}

int		ft_invalid_input(char c, t_printf *elem)
{
	int		count;

	count = 1;
	if (elem->width)
		count = with_width_invalid(c, elem);
	else
		ft_putchar(c);
	return (count);
}
