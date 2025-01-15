/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:47:49 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:47:49 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push_all_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	push;

	stack_size = count_size(*stack_a);
	push = 0;
	while (stack_size - push > 3)
	{
		pb(stack_a, stack_b);
		push++;
	}
}

void	sort_other(t_stack **stack_a, t_stack **stack_b)
{
	push_all_stack_b(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
	{
		search_target_pos(stack_a, stack_b);
		calculate_distance(stack_a, stack_b);
		shortest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		last_arrange(stack_a);
}
