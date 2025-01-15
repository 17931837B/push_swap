/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:43:14 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:43:14 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_stack	*search_max_value(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*max_pos;
	int		max_value;

	current = stack_a;
	max_pos = NULL;
	max_value = -2147483648;
	while (current)
	{
		if (current->value == -2147483648)
			current->index = 1;
		if (current->value > max_value && current->index == 0)
		{
			max_value = current->value;
			max_pos = current;
		}
		current = current->next;
	}
	return (max_pos);
}

void	compression(t_stack *stack_a, int stack_size)
{
	t_stack	*max_pos;

	while (stack_size > 0)
	{
		max_pos = search_max_value(stack_a);
		if (max_pos != NULL)
			max_pos->index = stack_size - 1;
		stack_size --;
	}
}
