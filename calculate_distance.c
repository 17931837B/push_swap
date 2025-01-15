/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:23:39 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:23:39 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	calculate_distance(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;
	int		count;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = count_size(tmp_a);
	size_b = count_size(tmp_b);
	count = size_b;
	while (count)
	{
		count--;
		tmp_b->aom_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->aom_b = (size_b - tmp_b->pos) * -1;
		tmp_b->aom_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->aom_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
