/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 05:52:33 by cboiron           #+#    #+#             */
/*   Updated: 2018/04/14 22:19:32 by cboiron          ###   ########.fr       */
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
	//if ((ft_atoi(str)) == size - (PROG_NAME_LENGTH + COMMENT_LENGTH)) {
//	}
	/*else
	{
		ft_putendl("Erreur dans le header");
		exit(EXIT_FAILURE);
	}*/
		vm->tab_champ[nb_player].weight = size -
				(PROG_NAME_LENGTH + COMMENT_LENGTH);
		//printf("size  %d \n", vm->tab_champ[nb_player].weight);
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
	read(vm->fd, str, 4); // On lit le magic number
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
