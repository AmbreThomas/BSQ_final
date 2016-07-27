/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopvet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 16:09:23 by elopvet           #+#    #+#             */
/*   Updated: 2016/07/27 10:13:53 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include "bsq.h"
#define BUF_SIZE 4096

void	ft_argtostr(char **str)
{
	char	*buf;
	char	*strcpy;
	int		readnb;
	int		sizestr;

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	strcpy = 0;
	readnb = -1;
	sizestr = 1;
	while (readnb)
	{
		strcpy = (char *)malloc(sizeof(char) * sizestr);
		ft_strcpy(strcpy, *str);
		free(*str);
		readnb = read(0, buf, BUF_SIZE);
		buf[readnb] = '\0';
		sizestr += readnb;
		*str = (char *)malloc(sizeof(char) * sizestr);
		ft_strcpy(*str, strcpy);
		free(strcpy);
		ft_strcat(*str, buf);
	}
	free(buf);
}
