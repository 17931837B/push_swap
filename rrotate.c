/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:46:42 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:46:42 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*edge;
	t_stack	*edge2;

	edge = get_stack_bottom(*stack);
	edge2 = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = edge;
	(*stack)->next = tmp;
	edge2->next = NULL;
}

void	rra(t_stack **stack_a)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 4);
}
