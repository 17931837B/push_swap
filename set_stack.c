/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:47:02 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:47:02 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_stack	*init_set_stack(int num)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = num;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->aom_a = -1;
	new->aom_b = -1;
	new->next = NULL;
	return (new);
}

static void	others_set_stack(t_stack **stack, t_stack *new)
{
	t_stack	*edge;

	if (!new)
		return ;
	if (*stack)
	{
		edge = *stack;
		while (edge->next != NULL)
			edge = edge->next;
		edge->next = new;
		return ;
	}
	else
		*stack = new;
}

t_stack	*set_stack(int ac, char **av)
{
	t_stack		*stack_a;
	long long	num;
	int			i;

	stack_a = NULL;
	num = 0;
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (i == 1)
			stack_a = init_set_stack(num);
		else
			others_set_stack(&stack_a, init_set_stack(num));
		i++;
	}
	return (stack_a);
}
