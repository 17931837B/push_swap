/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:48:02 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:48:02 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sa_rra(t_stack **stack_a)
{
	sa(stack_a);
	rra(stack_a);
}

static void	sa_ra(t_stack **stack_a)
{
	sa(stack_a);
	ra(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int		pos1;
	int		pos2;
	int		pos3;

	pos1 = (*stack_a)->index;
	pos2 = (*stack_a)->next->index;
	pos3 = (*stack_a)->next->next->index;
	if (pos3 < pos2 && pos2 < pos1)
		sa_rra(stack_a);
	else if (pos2 < pos1 && pos1 < pos3)
		sa(stack_a);
	else if (pos2 < pos3 && pos3 < pos1)
		ra(stack_a);
	else if (pos1 < pos3 && pos3 < pos2)
		sa_ra(stack_a);
	else
		rra(stack_a);
}
