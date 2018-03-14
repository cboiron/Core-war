/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:18:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/03/14 17:28:09 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../includes/struct.h"

/*
** Problème au niveau du malloc de la structure ?
** ==> Je n'arrive pas, la fatigue sans doute...
** ==> Il suffit de mettre les différentes données dans la structure qu'on
**					utilisera juste après
*/


void		init_vm(t_vm *vm)
{
	vm = ft_memalloc(sizeof(t_vm));
	vm->nbr_next = 0;
	vm->nbr_cycle = -1;
	vm->tab_champ[0].weight = 0;
	//vm->tab_champ[0] = ft_memalloc(sizeof(t_champ));
}

int			usage(void)
{
	ft_putendl("usage : ./corewar [-dump nbr_cycles] [[-n number] \
champion1.cor] ...");
	/*
	ft_printf("Usage de bas du corewar:  ./corewar \
[-dump nbr_cycles] [[-n number] champion1.cor] ...\n\
#### Prérequis ##########################################################\n\
- Pour l'utilisation de la vm, il vous faut un \"champion.s\".\n\
Celui-ci doit être passé dans l'asm pour pouvoir être utilisé.\n\
- Un minimum d'un champion est demandé sans quoi la partie de démarera pas.\n\
#### PARAM ##########################################################\n\
-dump nbr_cycles : Au bout de nbr_cycles cycles d’exécution, dump la mémoire \n\
sur la sortie standard, puis quitte la partie. La mémoire doit être dumpée au \n\
format hexadécimal, avec 32 octets par ligne.\n\
-n number : Fixe le numéro du prochain joueur. Si absent, le joueur aura le \n\
prochain numéro libre dans l’ordre des paramètres. Le dernier joueur aura le \n\
premier processus dans l’ordre d’exécution.\n\
######################################################################\n");
	 */
	exit(EXIT_FAILURE);
	return (0);
}

int			main(int argc, char **argv)
{
	t_vm	vm;

	if (argc < 2)
		usage();
	init_vm(&vm);
	create_arena(&vm);
	if (get_param(argv, &vm, argc) == 0)
		usage();
	load_champs(&vm);
	//dump_arena(&vm);
	//ft_printf("%s\n", argv[0]);
	//exit(EXIT_SUCCESS);
	return (0);
}
