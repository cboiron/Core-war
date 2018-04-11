/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:18:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/11 05:01:32 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../includes/struct.h"

void		init_vm(t_vm *vm)
{
	vm = ft_memalloc(sizeof(t_vm));
	vm->fd = 0;
	vm->dump_cycle = -1;
	vm->nbr_next = 0;
	vm->cycle = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
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
	init(&vm);
	//vm.tab_champ[0].id = -5;
	ft_putnbr(vm.tab_champ[0].id);
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
