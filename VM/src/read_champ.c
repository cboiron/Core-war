/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 05:52:33 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/18 04:28:22 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_magic(const char *str)
{
	int	magic[4];

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

void		check_size(t_vm *vm, int size, int nb_player, char *str)
{
	unsigned int size_bit;
	int			real_size;

	size_bit = str[0];
	size_bit <<= 8;
	size_bit |= str[1];
	size_bit <<= 8;
	size_bit |= str[2];
	size_bit <<= 8;
	size_bit |= str[3];
	real_size = size - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	printf("size %d\n", real_size);
	if (real_size > CHAMP_MAX_SIZE)
	{
		ft_putendl("Champion trop lourd");
		exit(EXIT_FAILURE);
	}
	if (real_size != size_bit)
	{
		printf("size dans header%d\n", size_bit);
		vm->tab_champ[nb_player].weight = real_size;
		printf("Probleme de taille dans le header\n");
		exit(EXIT_FAILURE);
	}
}

void		cpy_prog(t_vm *vm, unsigned char *prog, int num_player)
{
	int	index;

	if (!(vm->tab_champ[num_player].prog = malloc(sizeof(unsigned char) * \
	vm->tab_champ[num_player].weight - 8)))
		exit(EXIT_FAILURE);
	index = 0;
	while (index < vm->tab_champ[num_player].weight - 8)
	{
		vm->tab_champ[num_player].prog[index] = prog[index];
		 index++;
	}
}

/*
 * Verfier magic number et size du champion
 * */

void		read_champ(t_vm *vm, int nbr_player)
{
	char	str[PROG_NAME_LENGTH];
	int		size;
	char	comment[COMMENT_LENGTH];
	int		ret;

	size = 0;
	//if (nbr_player != -1)
	//	nbr_player = vm->nbr_next;
	printf("nb player = %d  \n", nbr_player);
	size = lseek(vm->fd, 0, SEEK_END);
	lseek(vm->fd, 0, SEEK_SET);
	ft_bzero(str, 4);
	read(vm->fd, str, 4); // On lit le magic number
	check_magic(str);
	read(vm->fd, str, PROG_NAME_LENGTH); // On lit le nom du joueur
	vm->tab_champ[nbr_player].name = ft_strdup(str);
	read(vm->fd, str, 4); // Octets vides
	read(vm->fd, str, 4); //Taille du champion en hexa
	check_size(vm, size, nbr_player, str);
	read(vm->fd, str, 4); // Octets vides
	read(vm->fd, comment, COMMENT_LENGTH); //commentaire
	ft_strcpy(vm->tab_champ[nbr_player].comment, comment);
	ft_bzero(comment, COMMENT_LENGTH);
	ret = read(vm->fd, comment, vm->tab_champ[nbr_player].weight - 8);
	cpy_prog(vm, (unsigned char*)comment, nbr_player);
	if (vm->tab_champ[nbr_player].id == -1)
		vm->tab_champ[nbr_player].id = vm->nbr_next + 1;

	vm->nbr_next++;
}
