/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:13:35 by cboiron           #+#    #+#             */
/*   Updated: 2016/11/20 20:35:36 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}
