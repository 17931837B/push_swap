/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:42:56 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:42:56 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	check_num(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '+' || av[i] == '-') && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (1);
	return (0);
}

static int	check_minus(const char *s1, const char *s2)
{
	if (s1[0] == '-')
	{
		if (s2[0] != '-')
			return (1);
	}
	else
	{
		if (s2[0] == '-')
			return (1);
	}
	return (0);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_minus(s1, s2))
		return (1);
	if (s1[i] == '+' || s1[i] == '-')
		i++;
	while (s1[i] == '0' && s1[i + 1] != '\0')
		i++;
	if (s2[j] == '+' || s2[j] == '-')
		j++;
	while (s2[j] == '0' && s2[j + 1] != '\0')
		j++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((int)s1[i] - (int)s2[j]);
}

static int	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (j != i && ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(char **av)
{
	int			i;
	long long	num;

	i = 1;
	while (av[i])
	{
		if (check_num(av[i]))
			return (1);
		num = ft_atoi(av[i]);
		if (num < -2147483648 || num > 2147483647)
			return (1);
		i++;
	}
	if (check_duplicates(av))
		return (1);
	return (0);
}
