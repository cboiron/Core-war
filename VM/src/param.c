/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:32:14 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/04 02:36:16 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			param_n(t_vm *vm, char **av, int *i, int ac)
{
	int		id;

	if (ac > (*i) + 1)
	{
		(*i)++;
		if (ft_isnumber(av[*i]))
		{
			id = ft_atoi(av[*i]);
			(*i)++;
			return (id);
		}
		else
		{
			ft_putendl("Pas de numéro apres le -n.");
			usage();
		}
	}
	else
	{
		ft_putendl("Pas de champion après le numéro demandé.");
		usage();
	}
	return (vm->nbr_next);
}

int			ft_isnumber(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

static void	champs(t_vm *vm, char *arg)
{
	if ((vm->fd = open(arg, O_RDONLY)) >= 0 && vm->nbr_next <= 3)
	{
		read_champ(vm, vm->nbr_next);
		close(vm->fd);
	}
	else if (vm->nbr_next >= 4)
	{
		ft_putendl("Nombre de champion trop eleve");
		exit(1);
	}
	else
		usage();
}

int			get_param(char **av, t_vm *vm, int ac)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (((ft_strcmp(av[i], "-n") == 0) || ft_strcmp(av[i], "-dump") == 0))
		{
			if (ft_strcmp(av[i], "-dump") == 0 && vm->dump_cycle == -1
					&& ac > i + 2 && ft_isnumber(av[i + 1]))
			{
				i++;
				vm->dump_cycle = ft_atoi(av[i]);
				i++;
			}
			if (ft_strcmp(av[i], "-n") == 0)
				vm->tab_champ[vm->nbr_next].id = param_n(vm, av, &i, ac);
		}
		champs(vm, av[i]);
	}
	if (vm->nbr_next == 0)
	{
		ft_putendl("Aucun champion .cor dans l'arene");
		return (0);
	}
	return (1);
}
