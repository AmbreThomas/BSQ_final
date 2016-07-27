/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 10:06:16 by athomas           #+#    #+#             */
/*   Updated: 2016/07/27 13:10:30 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"

int		main(int ac, char **av)
{
	char **map;

	map = 0;
	if (ac >= 2)
		map = ouvrir_fichier(ac - 1, av);
	else
	{
		map = (char**)malloc(sizeof(char*) * 2);
		map[0] = 0;
		ft_argtostr(map);
		map[1] = 0;
	}
	resoudre(map);
	free(*map);
	return (0);
}
