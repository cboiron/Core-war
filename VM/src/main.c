/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:18:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/03/07 05:25:51 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>


void	read_champ(int fd)
{
	char	str[PROG_NAME_LENGTH];
	int		size;
	int		i;
	char	comment[COMMENT_LENGTH];

	i = 0;
	{
		size = lseek(fd, 0, SEEK_END);
		ft_putstr("size = ");
		ft_putnbr(size);
		ft_putendl("");
		if (size - (PROG_NAME_LENGTH + COMMENT_LENGTH) > CHAMP_MAX_SIZE)
			ft_putendl("champion trop lourd");
		lseek(fd, 0, SEEK_SET);
		read(fd, str, 4); // On lit le magic number
		printf("%x", (unsigned char)str[0]);
		printf("%x", (unsigned char)str[1]);
		printf("%x", (unsigned char)str[2]);
		printf("%x\n", (unsigned char)str[3]);
		read(fd, str, PROG_NAME_LENGTH); // On lit le nom du joueur
		ft_putendl(str);
		read(fd, str, 4); // Octets vides
		read(fd, str, 4); //Taille du champion en hexa
		printf("%x", (unsigned char)str[0]);
		printf("%x", (unsigned char)str[1]);
		printf("%x", (unsigned char)str[2]);
		printf("%x\n", (unsigned char)str[3]);
		read(fd, comment, COMMENT_LENGTH);
		ft_putendl(comment);
		/*while (i < PROG_NAME_LENGTH)
		{
			printf("%x", str[i++]);
		}
			printf("\n");
			*/
	}
}

int		get_players(char **av)
{
	int	i;
	int	fd;

	fd = 0;
	i = 1;
	while (av[i])
	{
		if ((fd = open(av[i], O_RDONLY)) >= 0)
		{
			read_champ(fd);
			i++;
		}
	}
	return (1);
}

int		get_flags(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
		{
			if (ft_strcmp(av[i], "-n") == 0)
				ft_putendl("nb player");
			else if (ft_strcmp(av[i], "-dump") == 0)
				ft_putendl("dump");
		}
		i++;
	}
	return (1);
}

int usage(void)
{
	ft_putendl("Usage");
	/*
	ft_printf("Rentrer ici l'usage.\n");
	ft_printf("./corewar [joueur1] ...\n");
	ft_printf("Maximum de joueur : 4\n");
	exit(EXIT_FAILURE);
	*/
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		usage();
	get_players(argv);
	//get_flags(argv);
	//create_arena();
	//ft_printf("%s\n", argv[0]);

	return (0);
}
