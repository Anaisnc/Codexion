/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:28:07 by ancourt           #+#    #+#             */
/*   Updated: 2026/05/20 16:28:11 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <unistd.h>
# include <stdlib.h>

/* parsing_utils.c */
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);

/* error.c */
int		error_message(char *str);

/* parsing.c */
int		is_numeric(char *str);
int		is_fifo_or_edf(char *str);
int		check_args(int ac, char **av);

#endif
