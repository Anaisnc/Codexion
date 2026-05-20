/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:39:13 by ancourt           #+#    #+#             */
/*   Updated: 2026/05/20 16:47:28 by ancourt          ###   ########.fr       */
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

int main(int ac, char **av)
{
    int *args_tab;
    if (check_args(ac, av))
        return (error_message("Arguments invalids."));
    args_tab = get_args(av);
    if (!args_tab)
        return (error_message("Argument table could not be created."));
    free(args_tab);
    return (0);
}

