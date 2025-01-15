/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:43:03 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:43:03 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rr_both(t_stack **stack_a, t_stack **stack_b,
						int *aom_a, int *aom_b)
{
	while (*aom_a > 0 && *aom_b > 0)
	{
		(*aom_a)--;
		(*aom_b)--;
		rr(stack_a, stack_b);
	}
}

static void	rrr_both(t_stack **stack_a, t_stack **stack_b,
												int *aom_a, int *aom_b)
{
	while (*aom_a < 0 && *aom_b < 0)
	{
		(*aom_a)++;
		(*aom_b)++;
		rrr(stack_a, stack_b);
	}
}

static void	ra_or_rra(t_stack **stack_a, int *aom)
{
	while (*aom)
	{
		if (*aom > 0)
		{
			ra(stack_a);
			(*aom)--;
		}
		else if (*aom < 0)
		{
			rra(stack_a);
			(*aom)++;
		}
	}
}

static void	rb_or_rrb(t_stack **stack_b, int *aom)
{
	while (*aom)
	{
		if (*aom > 0)
		{
			rb(stack_b);
			(*aom)--;
		}
		else if (*aom < 0)
		{
			rrb(stack_b);
			(*aom)++;
		}
	}
}

void	choice_move(t_stack **stack_a, t_stack **stack_b, int aom_a, int aom_b)
{
	if (aom_a < 0 && aom_b < 0)
		rrr_both(stack_a, stack_b, &aom_a, &aom_b);
	else if (aom_a > 0 && aom_b > 0)
		rr_both(stack_a, stack_b, &aom_a, &aom_b);
	ra_or_rra(stack_a, &aom_a);
	rb_or_rrb(stack_b, &aom_b);
	pa(stack_a, stack_b);
}
