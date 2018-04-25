/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:58:03 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/26 01:51:00 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** mets size_to_here dans chaque buff
*/

static void			size_all(t_asm *env)
{
	t_parsing		*tmp;
	unsigned int	size_max;

	tmp = env->buff;
	size_max = 0;
	while (tmp)
	{
		size_max += tmp->size;
		tmp->size_to_here = size_max;
		tmp = tmp->next;
	}
}

/*
** permets de quitter le programme après avoir affiché l'erreur
*/

void				msg_error(char *msg, int index)
{
	if (!index)
		ft_printf("%s\n", msg);
	else
		ft_printf("erreur de syntax à la ligne : %d| --> %s\n", index, msg);
	exit(EXIT_FAILURE);
}

/*
** fonction d'initialisation des la structure
*/

static void			ft_init(t_asm *env)
{
	env->buff = NULL;
	env->verif_name = 0;
	env->verif_com = 0;
	env->header = (t_header*)malloc((sizeof(unsigned int) * 2) +
									sizeof(char) *
									(PROG_NAME_LENGTH +
									COMMENT_LENGTH + 2));
	env->header->magic = COREWAR_EXEC_MAGIC;
}

/*
** fonction servant à détecter les erreurs :captainobvious:
*/

static int			detect_errors(int argc, char *champ, t_asm *env)
{
	int				fd;
	int				x;
	char			*tmp;

	if (argc != 2)
		msg_error(USAGE, 0);
	x = ft_strlen(champ) - 1;
	if (champ[x] != 's' || champ[x - 1] != '.')
		msg_error(USAGE, 0);
	tmp = ft_strsub(champ, 0, x - 1);
	env->champ_name = ft_strjoin(tmp, ".cor");
	if ((fd = open(champ, O_RDONLY)) == -1)
		msg_error(ERR_OPEN, 0);
	if (close(fd) == -1)
		msg_error(ERR_CLOSE, 0);
	return (1);
}

int					main(int argc, char **argv)
{
	t_asm			env;

	detect_errors(argc, argv[1], &env);
	ft_init(&env);
	parsing(argv[argc - 1], &env);
	verif_size(&env);
	size_all(&env);
	write_out(&env);
	ft_printf("Writing output program to %s\n", env.champ_name);
	exit(EXIT_SUCCESS);
	return (0);
}
