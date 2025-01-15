/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:47:15 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:47:15 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	shortest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		shortest;
	int		aom_a;
	int		aom_b;

	tmp = *stack_b;
	shortest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->aom_a) + ft_abs(tmp->aom_b) < ft_abs(shortest))
		{
			shortest = ft_abs(tmp->aom_b) + ft_abs(tmp->aom_a);
			aom_a = tmp->aom_a;
			aom_b = tmp->aom_b;
		}
		tmp = tmp->next;
	}
	choice_move(stack_a, stack_b, aom_a, aom_b);
}
