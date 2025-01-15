/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_target_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:46:49 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:46:49 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_target(t_stack **stack_a, int b_idx, int target_pos)
{
	t_stack	*tmp;
	int		target_index;

	target_index = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > b_idx && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	return (-1);
}

int	retry_get_target(t_stack **stack_a)
{
	t_stack	*tmp;
	int		target_index;
	int		target_pos;

	target_index = INT_MAX;
	target_pos = -1;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

static void	get_pos(t_stack **stack)
{
	t_stack	*res;
	int		i;

	res = *stack;
	i = 0;
	while (res)
	{
		res->pos = i;
		res = res->next;
		i++;
	}
}

void	search_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		target_pos;

	current = *stack_b;
	get_pos(stack_a);
	get_pos(stack_b);
	while (current)
	{
		target_pos = get_target(stack_a, current->index, -1);
		if (target_pos == -1)
			target_pos = retry_get_target(stack_a);
		current->target_pos = target_pos;
		current = current->next;
	}
}
