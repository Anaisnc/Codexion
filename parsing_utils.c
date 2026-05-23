/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:10:36 by ancourt           #+#    #+#             */
/*   Updated: 2026/05/23 12:17:44 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int ft_strlen(char *str)
{
	int len;

	len = 0;

	while(str[len])
		len++;
	return(len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*st1;
	const unsigned char	*st2;

	st1 = (const unsigned char *)s1;
	st2 = (const unsigned char *)s2;
	i = 0;
	while ((st1[i] || st2[i]) && i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	validate_long_tab(long *tab)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (tab[i] > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

