/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:32:13 by ancourt           #+#    #+#             */
/*   Updated: 2026/05/23 12:19:43 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

     /*args_tab[0] = number_of_coders
     args_tab[1] = time_to_burnout      (ms)
     args_tab[2] = time_to_compile      (ms)
     args_tab[3] = time_to_debug        (ms)
     args_tab[4] = time_to_refactor     (ms)
     args_tab[5] = number_of_compiles_required
     args_tab[6] = dongle_cooldown      (ms)
     av[8]       = scheduler            (fifo | edf)*/

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

static long	*get_long_tab(char **av)
{
	long	*tab;
	int		i;

	tab = malloc(7 * sizeof(long));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 7)
	{
		tab[i] = ft_atol(av[i + 1]);
		i++;
	}
	return (tab);
}

int	*get_args(char **av)
{
	long	*tab_long;
	int		*tab;
	int		i;

	tab_long = get_long_tab(av);
	if (!tab_long || validate_long_tab(tab_long))
	{
		free(tab_long);
		return (NULL);
	}
	tab = malloc(7 * sizeof(int));
	if (!tab)
	{
		free(tab_long);
		return (NULL);
	}
	i = 0;
	while (i < 7)
	{
    	tab[i] = (int)tab_long[i];
    	i++;
	}
	free(tab_long);
	return (tab);
}
