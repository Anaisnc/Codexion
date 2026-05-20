/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:39:13 by ancourt           #+#    #+#             */
/*   Updated: 2026/05/20 16:44:32 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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

