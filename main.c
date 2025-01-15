/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:46:03 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:46:03 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	**deforme_argv(char *numbers)
{
	char	**res;
	char	*tmp;

	if (numbers == NULL || *numbers == '\0')
		exit (0);
	tmp = ft_strjoin("a ", numbers);
	res = ft_split(tmp, ' ');
	free(tmp);
	return (res);
}

static int	count_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static void	frees(t_stack **a, t_stack **b, int dq_flag, char **argv)
{
	free_stack(a);
	free_stack(b);
	if (dq_flag)
		double_free(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		dq_flag;

	dq_flag = 0;
	if (argc == 2)
	{
		dq_flag = 1;
		argv = deforme_argv(argv[1]);
		argc = count_argv(argv);
	}
	if (argc < 2)
		return (0);
	if (check_input(argv))
		return (double_free_and_error(argv, dq_flag));
	stack_a = set_stack(argc, argv);
	stack_b = NULL;
	stack_size = count_size(stack_a);
	compression(stack_a, stack_size + 1);
	select_way(&stack_a, &stack_b, stack_size);
	frees(&stack_a, &stack_b, dq_flag, argv);
	return (0);
}
