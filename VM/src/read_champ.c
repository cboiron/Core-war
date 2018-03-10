/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 05:52:33 by cboiron           #+#    #+#             */
/*   Updated: 2018/03/10 05:52:56 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		check_size(t_vm *vm, int size, int nb_player) {
	if (size - (PROG_NAME_LENGTH + COMMENT_LENGTH) > CHAMP_MAX_SIZE)
	{
		ft_putendl("champion trop lourd");
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(ft_atoi(str), size) == 0)
		vm->champ[nbr_player]->weight = size;
	else
	{
		ft_putendl("Erreur dans le header");
		exit(EXIT_FAILURE);
	}
}

void		read_champ(t_vm *vm, int nbr_player)
{
	char	str[PROG_NAME_LENGTH];
	int		size;
	char	comment[COMMENT_LENGTH];

	if (nbr_player != -1)
		nbr_player = vm->nbr_next;
	size = lseek(vm->fd, 0, SEEK_END);
	lseek(vm->fd, 0, SEEK_SET);
	read(vm->fd, str, 4); // On lit le magic number
	if (ft_strcmp(str, COREWAR_EXEC_MAGIC != 0))
		usage(); // manque/mauvais magic number
	read(vm->fd, str, PROG_NAME_LENGTH); // On lit le nom du joueur
	vm->champ[nbr_player]->name = ft_strdup(str);
	read(vm->fd, str, 4); // Octets vides
	read(vm->fd, str, 4); //Taille du champion en hexa
	check_size(vm, size, nbr_player);
	read(vm->fd, comment, COMMENT_LENGTH); //commentaire
	vm->champ[nbr_player]->comment = ft_strdup(comment);
	read(vm->fd, comment, vm->champ[nbr_player]->weight);
	vm->champ[nbr_player]->prog = ft_strdup(comment);
	vm->nbr_next++;
}
