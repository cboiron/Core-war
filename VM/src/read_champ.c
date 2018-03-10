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

void		check_size(t_vm *vm, int size, int nb_player, char *str)
{
	if (size - (PROG_NAME_LENGTH + COMMENT_LENGTH) > CHAMP_MAX_SIZE)
	{
		ft_putendl("champion trop lourd");
		exit(EXIT_FAILURE);
	}
	/*
	 * Besoin de atoi base
	printf("%d size = \n", size - (PROG_NAME_LENGTH + COMMENT_LENGTH));
	printf("%d atoi \n", ft_atoi(str));
	*/
	if ((ft_atoi(str)) == size - (PROG_NAME_LENGTH + COMMENT_LENGTH)) {
		vm->tab_champ[nb_player].weight = size -
				(PROG_NAME_LENGTH + COMMENT_LENGTH);
		ft_putendl("lololol");
		printf("size  %d \n", vm->tab_champ[nb_player].weight);
	}
	/*else
	{
		ft_putendl("Erreur dans le header");
		exit(EXIT_FAILURE);
	}*/

}

void		read_champ(t_vm *vm, int nbr_player)
{
	char	str[PROG_NAME_LENGTH];
	int		size;
	char	comment[COMMENT_LENGTH];

	if (nbr_player != -1)
		nbr_player = vm->nbr_next;
	printf("%d nb player = \n", nbr_player);
	size = lseek(vm->fd, 0, SEEK_END);
	lseek(vm->fd, 0, SEEK_SET);
	read(vm->fd, str, 4); // On lit le magic number
	//if ((ft_atoi(str) != COREWAR_EXEC_MAGIC))
	//	usage(); // manque/mauvais magic number
	read(vm->fd, str, PROG_NAME_LENGTH); // On lit le nom du joueur
	printf("%d num joueur\n",nbr_player);
	vm->tab_champ[nbr_player].name = ft_strdup(str);
	printf("nom = %s\n", vm->tab_champ[nbr_player].name);
	read(vm->fd, str, 4); // Octets vides
	read(vm->fd, str, 4); //Taille du champion en hexa
	check_size(vm, size, nbr_player, str);
	read(vm->fd, comment, COMMENT_LENGTH); //commentaire
	ft_strcpy(vm->tab_champ[nbr_player].comment, comment);
	read(vm->fd, comment, vm->tab_champ[nbr_player].weight);
	vm->tab_champ[nbr_player].prog = ft_strdup(comment);
	printf("comment = %s\n", vm->tab_champ[nbr_player].comment);
	vm->nbr_next++;

}
