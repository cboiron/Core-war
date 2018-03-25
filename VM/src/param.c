/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:32:14 by abrichar          #+#    #+#             */
/*   Updated: 2018/03/21 05:43:23 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	param_n(t_vm *vm, int number_player, char **av, int *i)
{
	if (match(av[++(*i)], "*.cor"))
		read_champ(vm, number_player);
	else
	{
		ft_putendl("Pas de champion après le numéro demandé.");
		usage();
	}
	return (1);
}

int ft_isnumber(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

void	champs(t_vm *vm, char *arg)
{
	if ((match(arg, "*.cor")))
	{
		if ((vm->fd = open(arg, O_RDONLY)) >= 0 && vm->nbr_next < 3)
		{
			read_champ(vm, vm->nbr_next);
			close(vm->fd);
		}
		else
			usage();
	}
}

int get_param(char **av, t_vm *vm, int ac)
{
	int i;

	i = 1;
	while (av[i])
	{
		champs(vm, av[i]);
		if (((ft_strcmp(av[i], "-n") == 0) ||
					ft_strcmp(av[i], "-dump") == 0) && ac >= i + 2 &&
				(ft_isnumber(av[++i]) == 0))
		{
		if (ft_strcmp(av[i], "-n") == 0)
			param_n(vm, ft_atoi(av[++i]), av, &i);
		else if (ft_strcmp(av[i], "-dump") == 0 && vm->dump_cycle == -1)
			vm->dump_cycle = ft_atoi(av[i]);
		else
			return (0);
		}
		i++;
	}
	if (vm->nbr_next == 0)
	{
		ft_putendl("Aucun champion .cor dans l'arene");
		return (0);
	}
	return (1);
}
