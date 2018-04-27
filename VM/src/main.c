/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:18:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/27 07:17:03 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../includes/struct.h"

void		init_vm(t_vm *vm)
{
	vm = ft_memalloc(sizeof(t_vm));
	//vm->tab_champ[0] = ft_memalloc(sizeof(t_champ));
}

void	init(t_vm *vm)
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
//	sleep(10);
	//dump_arena(&vm);
	//dump_arena(&vm);
	//ft_printf("%s\n", argv[0]);
	//exit(EXIT_SUCCESS);
	return (0);
}
