/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:32:13 by ancourt           #+#    #+#             */
/*   Updated: 2026/05/20 16:36:47 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int is_fifo_or_edf(char *str)
{
    return (ft_strncmp(str, "fifo", 4) == 0 || ft_strncmp(str, "edf", 3) == 0);
}

int is_numeric(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return(1);
}

int check_args(int ac, char **av)
{
    int i;

    if (ac != 9)
        return (error_message("Number of arguments is not 8."));
    if (!(is_fifo_or_edf(av[8])))
        return (error_message("Scheduler rejected."));
    i = 1;
    while (i < 8)
    {
        if (is_numeric(av[i]))
            i++;
        else
            return (error_message("Non numerical arguments or negative intergers rejected."));
    }
    return (0);
}

int *get_args(char **av)
{
    int *tab;
    int i;

    tab = malloc(7 * sizeof(int));
    if (!tab)
        return (NULL);
    i = 0;
    while (i < 7)
    {
        tab[i] = ft_atoi(av[i + 1]);
        i++;
    }
    return (tab);
}
