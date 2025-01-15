/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:46:56 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:46:56 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	select_way(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if (stack_size >= 500 && !is_sorted(*stack_a))
		sort_over_500(stack_a, stack_b);
	else if (stack_size >= 4 && stack_size < 500 && !is_sorted(*stack_a))
		sort_other(stack_a, stack_b);
}
