/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:06:54 by lmarcel           #+#    #+#             */
/*   Updated: 2016/07/27 12:25:55 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int		file_present(char *map)
{
	if (map[0] == 0)
	{
		ft_putstr_err("map error\n");
		return (0);
	}
	return (1);
}

int		nombre_colonnes1(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int		ft_error_lenght_lignes(char **map)
{
	int a;
	int i;
	int j;
	int error;

	i = 2;
	a = nombre_colonnes1(map[1]);
	while (map[i])
	{
		error = 0;
		j = 0;
		while (map[i][j++])
			error++;
		if (a != error)
		{
			ft_putstr_err("map error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_error_carac_firstligne(char **map)
{
	int i;
	int j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == obstacle(map[0]) || map[i][j] == vide(map[0])))
			{
				ft_putstr_err("map error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
