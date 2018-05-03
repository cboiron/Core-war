/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:18:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/03 23:16:19 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../includes/struct.h"

static void	free_vm(t_vm *vm)
{
	int	i;

	printf("nombre de joueurs %d", vm->nbr_next);
	i = 0;
	while (i < vm->nbr_next)
	{
		//free(vm->tab_champ[i].name);
		//free(vm->tab_champ[i].prog);
		//free(&vm->tab_champ[i]);
		i++;
	}
	vm = NULL;
}

void		init_vm(t_vm *vm)
{
	vm = ft_memalloc(sizeof(t_vm));
}

static void	init(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		vm->tab_champ[i].weight = 0;
		vm->tab_champ[i].id = -1;
		i++;
	}
	vm->fd = 0;
	vm->dump_cycle = -1;
	vm->nbr_next = 0;
	vm->cycle = 0;
	vm->last_check = 0;
	vm->total_lives_period = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycle_before_checking = CYCLE_TO_DIE;
}

int			usage(void)
{
	ft_putendl("usage : ./corewar [-dump nbr_cycles] [[-n number] \
			champion1.cor] ...");
	exit(EXIT_FAILURE);
	return (0);
}

int			main(int argc, char **argv)
{
	t_vm	vm;

	if (argc < 2)
		usage();
	init_vm(&vm);
	vm.last_check = 0;
	vm.cycle_to_die = CYCLE_TO_DIE;
	init(&vm);
	create_arena(&vm);
	if (get_param(argv, &vm, argc) == 0)
		usage();
	load_champs(&vm);
	play(&vm);
	free_vm(&vm);
	//free(&vm);
	sleep(10);
	return (0);
}
