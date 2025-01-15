/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:47:23 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:47:23 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pb_three_pa(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_four_action(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos == 0)
		pb_three_pa(stack_a, stack_b);
	if (pos == 1)
	{
		ra(stack_a);
		pb_three_pa(stack_a, stack_b);
	}
	if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb_three_pa(stack_a, stack_b);
	}
	if (pos == 3)
	{
		rra(stack_a);
		pb_three_pa(stack_a, stack_b);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		pos;

	current = *stack_a;
	pos = 0;
	while (current)
	{
		if (current->index == 1)
			break ;
		current = current->next;
		pos ++;
	}
	sort_four_action(stack_a, stack_b, pos);
}
