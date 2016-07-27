/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 10:09:16 by athomas           #+#    #+#             */
/*   Updated: 2016/07/27 12:24:05 by athomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	**ouvrir_fichier(int ac, char **av);
void	ft_putstr_err(char *str);
void	ft_putchar_err(char c);
void	ft_argtostr(char **str);
void	ft_strcat(char *dest, char *src);
void	ft_strcpy(char *dest, char *src);
int		nombre_colonnes(char *map);
int		nombre_carac(char *map);
int		nombre_lignes(char *map);
char	**convertir_map(char *map);
int		ft_error_lenght_lignes(char **map);
int		ft_error_carac_firstligne(char **map);
char	obstacle(char *map);
char	vide(char *map);
char	plein(char *map);
void	afficher(char **map);
void	resoudre(char **map);
int		file_present(char *map);
int		**trouve_carre(char **map);
void	resolution_bsq(char **map);
void	dessiner_grille(int **conv, char **map, int *i, int *j);
void	afficher_grille(int **conv, char **map);
void	remplir_grille(int **conv, char **map);
int		ft_min(int a, int b, int c);
int		colonnes(char **map);
int		lignes(char **map);
void	dessiner_carre(char **map, int *i, int *j, int taille);

#endif
