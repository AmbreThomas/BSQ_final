/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 12:21:59 by athomas           #+#    #+#             */
/*   Updated: 2016/07/27 13:19:28 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

void	resoudre(char **map)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i])
	{
		if (file_present(map[i]))
		{
			new_map = convertir_map(map[i]);
			if (ft_error_carac_firstligne(new_map))
			{
				if (ft_error_lenght_lignes(new_map))
				{
					resolution_bsq(new_map);
					afficher(new_map);
				}
			}
			free(new_map);
		}
		i++;
	}
}

void	afficher(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}

void	resolution_bsq(char **map)
{
	int		**conv;
	int		*i;
	int		*j;
	int		a;
	int		b;

	a = 0;
	b = 0;
	i = &a;
	j = &b;
	conv = trouve_carre(map);
	remplir_grille(conv, map);
	dessiner_grille(conv, map, i, j);
	free(conv);
}

int		ft_min(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
			return (a);
	}
	if (b <= a)
	{
		if (b <= c)
			return (b);
	}
	if (c <= a)
	{
		if (c <= b)
			return (c);
	}
	return (0);
}

void	dessiner_carre(char **map, int *i, int *j, int taille)
{
	int ii;
	int jj;
	int tempj;
	int tempi;

	ii = *i + 1;
	jj = *j;
	tempj = jj - taille;
	tempi = ii - taille;
	while (ii > tempi)
	{
		while (jj > tempj)
		{
			map[ii][jj] = plein(map[0]);
			jj--;
		}
		jj += taille;
		ii--;
	}
}
