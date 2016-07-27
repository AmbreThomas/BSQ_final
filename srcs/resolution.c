/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:39:43 by athomas           #+#    #+#             */
/*   Updated: 2016/07/27 12:24:40 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <stdlib.h>

void	dessiner_grille(int **conv, char **map, int *i, int *j)
{
	int		ii;
	int		jj;
	int		temp;

	temp = 0;
	ii = lignes(map) - 2;
	while (ii >= 0)
	{
		jj = colonnes(map);
		while (jj >= 0)
		{
			if (conv[ii][jj] >= temp)
			{
				temp = conv[ii][jj];
				*i = ii;
				*j = jj;
			}
			jj--;
		}
		ii--;
	}
	dessiner_carre(map, i, j, temp);
}

void	remplir_grille(int **conv, char **map)
{
	int		i;
	int		j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 1 || j == 0)
			{
				conv[i - 1][j] = 1;
			}
			else
			{
				conv[i - 1][j] = ft_min(conv[i - 1][j - 1], conv[i - 2][j],
						conv[i - 2][j - 1]) + 1;
			}
			if (map[i][j] == obstacle(map[0]))
				conv[i - 1][j] = 0;
			j++;
		}
		i++;
	}
}

int		lignes(char **map)
{
	int		i;

	i = 1;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int		colonnes(char **map)
{
	int j;

	j = 0;
	while (map[1][j])
	{
		j++;
	}
	return (j);
}

int		**trouve_carre(char **map)
{
	int		**conv;
	int		i;
	int		j;

	conv = (int**)malloc(sizeof(int*) * lignes(map));
	i = 1;
	while (map[i])
	{
		j = 0;
		conv[i - 1] = (int*)malloc(sizeof(int) * colonnes(map));
		while (map[i][j])
		{
			conv[i - 1][j] = 0;
			j++;
		}
		conv[i - 1][j] = 0;
		i++;
	}
	conv[i - 1] = 0;
	return (conv);
}
