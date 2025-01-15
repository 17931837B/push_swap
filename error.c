/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:43:29 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:43:29 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL)
		free_stack(stack_a);
	if (stack_b == NULL)
		free_stack(stack_b);
	write(1, "Error\n", 6);
	return (1);
}

void	double_free(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	double_free_and_error(char	**argv, int dq_flag)
{
	if (dq_flag)
		double_free(argv);
	return (error(NULL, NULL));
}
