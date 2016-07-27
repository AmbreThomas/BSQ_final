/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 13:08:10 by athomas           #+#    #+#             */
/*   Updated: 2016/07/27 10:41:20 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"

int		nombre_colonnes(char *map)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i] != '\n')
	{
		nb++;
		i++;
	}
	return (nb);
}

int		nombre_lignes(char *map)
{
	int lignes;
	int i;

	lignes = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			lignes++;
		i++;
	}
	return (lignes);
}

int		nombre_carac(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

char	**convertir_map(char *map)
{
	char	**retour;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	retour = (char**)malloc(sizeof(char*) * nombre_lignes(map) + 1);
	retour[0] = (char*)malloc(sizeof(char) * nombre_carac(map) + 1);
	while (map[j] != '\n')
		retour[0][i++] = map[j++];
	retour[0][i] = '\0';
	i = 1;
	while (i < nombre_lignes(map))
	{
		j++;
		k = 0;
		retour[i] = (char*)malloc(sizeof(char) * nombre_colonnes(map) + 1);
		while (map[j] != '\n')
			retour[i][k++] = map[j++];
		retour[i][k] = '\0';
		i++;
	}
	retour[i] = 0;
	return (retour);
}
