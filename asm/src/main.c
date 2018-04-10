
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:58:03 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/11 00:35:24 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** fonction d'initialisation des la structure
*/
static void	ft_init(t_asm *env)
{
	env->verif_name = 0;
	env->verif_com = 0;
}

/*
** fonction servant à détecter les erreurs :captainobvious:
*/

static int	detect_errors(int argc, char *champ, t_asm *env)
{
	int		x;
	char	*tmp;

	if (argc != 2)
		return (-1);
	x = ft_strlen(champ) - 1;
	if (champ[x] != 's' || champ[x - 1] != '.')
		return (-1);
	tmp = ft_strsub(champ, 0, x - 1);
	env->champ_name = ft_strjoin(tmp, ".cor");
	return (1);
}

int			main(int argc, char **argv)
{
	t_asm env;

	if (detect_errors(argc, argv[1], &env) == -1)
		exit(EXIT_FAILURE);
	ft_init(&env);
	parsing(argv[argc - 1], &env);
	ft_printf("Writing output program to %s\n", env.champ_name);
	return(0);
}
