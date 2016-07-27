/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caractere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:12:31 by athomas           #+#    #+#             */
/*   Updated: 2016/07/27 12:18:43 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	obstacle(char *map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (map[i - 2]);
}

char	vide(char *map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (map[i - 3]);
}

char	plein(char *map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (map[i - 1]);
}
