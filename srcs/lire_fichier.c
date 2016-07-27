/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lire_fichier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 10:26:22 by athomas           #+#    #+#             */
/*   Updated: 2016/07/26 14:51:11 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"
#define BUF_SIZE 4096

int		nombre_octet(char *fichier)
{
	char	buf[BUF_SIZE];
	int		fd;
	int		count;
	int		ret;

	count = 0;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		count += ret;
	}
	return (count);
}

char	**ouvrir_fichier(int ac, char **av)
{
	char	**buf;
	int		ret;
	int		fd;
	int		i;

	i = 0;
	buf = (char**)malloc(sizeof(char*) * ac + 1);
	while (i < ac)
	{
		buf[i] = (char*)malloc(sizeof(char) * nombre_octet(av[i + 1]));
		fd = open(av[i + 1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_err("Fichier invalide\n");
			buf[i] = 0;
		}
		while ((ret = read(fd, buf[i], nombre_octet(av[i + 1]))))
		{
			buf[i][ret] = '\0';
		}
		close(fd);
		i++;
	}
	buf[i] = 0;
	return (buf);
}
