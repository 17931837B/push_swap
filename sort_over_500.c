/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:47:55 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:47:55 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	push_segment(t_stack **stack_a, t_stack **stack_b,
							int multiplier)
{
	int	push;
	int	i;
	int	stack_size;
	int	segment_size;

	push = 0;
	i = 0;
	stack_size = count_size(*stack_a);
	segment_size = stack_size / 4;
	while (i < stack_size && push < segment_size)
	{
		if ((*stack_a)->index <= segment_size * multiplier)
		{
			pb(stack_a, stack_b);
			push++;
		}
		else
			ra(stack_a);
		i++;
	}
	return (push);
}

static void	push_remaining(t_stack **stack_a, t_stack **stack_b,
								int stack_size, int count_push)
{
	while (stack_size - count_push > 3)
	{
		pb(stack_a, stack_b);
		count_push++;
	}
}

static void	push_all_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	count_push;

	stack_size = count_size(*stack_a);
	count_push = 0;
	count_push += push_segment(stack_a, stack_b, 1);
	count_push += push_segment(stack_a, stack_b, 2);
	count_push += push_segment(stack_a, stack_b, 3);
	push_remaining(stack_a, stack_b, stack_size, count_push);
}

void	sort_over_500(t_stack **stack_a, t_stack **stack_b)
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
