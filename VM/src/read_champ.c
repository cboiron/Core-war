/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 05:52:33 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 23:28:26 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			check_magic(const char *str)
{
	int				magic[4];

	magic[0] = str[3];
	magic[1] = str[2];
	magic[2] = str[1];
	magic[3] = str[0];
	if (magic[0] != -13 || magic[1] != -125 || magic[2] != -22 || magic[3] != 0)
	{
		ft_putendl("Le header d'un joueur est incorrect.");
		exit(1);
	}
}

static void			check_size(t_vm *vm, int size, int nb_player, char *str)
{
	unsigned int	size_bit;
	int				real_size;

	real_size = size - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	if (real_size > CHAMP_MAX_SIZE)
	{
		ft_putendl("Champion trop lourd");
		exit(EXIT_FAILURE);
	}
	size_bit = str[0];
	size_bit <<= 8;
	size_bit |= str[1];
	size_bit <<= 8;
	size_bit |= str[2];
	size_bit <<= 8;
	size_bit |= str[3];
	vm->tab_champ[nb_player].weight = real_size;
}

static void			cpy_prog(t_vm *vm, unsigned char *prog, int num_player)
{
	int				index;

	if (!(vm->tab_champ[num_player].prog = malloc(sizeof(unsigned char) * \
	vm->tab_champ[num_player].weight)))
		exit(EXIT_FAILURE);
	index = 0;
	while (index < vm->tab_champ[num_player].weight)
	{
		vm->tab_champ[num_player].prog[index] = prog[index];
		index++;
	}
}

void				read_champ(t_vm *vm, int nbr_player)
{
	char			str[PROG_NAME_LENGTH];
	int				size;
	char			comment[COMMENT_LENGTH];
	int				ret;

	size = 0;
	size = lseek(vm->fd, 0, SEEK_END);
	lseek(vm->fd, 0, SEEK_SET);
	ft_bzero(str, 4);
	read(vm->fd, str, 4);
	check_magic(str);
	read(vm->fd, str, PROG_NAME_LENGTH);
	vm->tab_champ[nbr_player].name = ft_strdup(str);
	read(vm->fd, str, 4);
	read(vm->fd, str, 4);
	check_size(vm, size, nbr_player, str);
	read(vm->fd, comment, COMMENT_LENGTH);
	ft_strcpy(vm->tab_champ[nbr_player].comment, comment);
	ft_bzero(comment, COMMENT_LENGTH);
	ret = read(vm->fd, comment, vm->tab_champ[nbr_player].weight);
	cpy_prog(vm, (unsigned char*)comment, nbr_player);
	if (vm->tab_champ[nbr_player].id == -1)
		vm->tab_champ[nbr_player].id = vm->nbr_next + 1;
	vm->nbr_next++;
}
