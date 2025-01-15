/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:46:12 by tobaba            #+#    #+#             */
/*   Updated: 2024-07-08 08:46:12 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				aom_a;
	int				aom_b;
	struct s_stack	*next;
}	t_stack;

void		calculate_distance(t_stack **stack_a, t_stack **stack_b);
void		choice_move(t_stack **stack_a, t_stack **stack_b,
				int aom_a, int aom_b);
void		compression(t_stack *stack_a, int stack_size);
int			check_input(char **av);
int			count_size(t_stack	*stack);
int			error(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
long long	ft_atoi(const char *str);
int			ft_isdigit(char c);
char		**ft_split(const char *str, char sep);
char		*ft_strjoin(char const *s1, char const *s2);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
void		last_arrange(t_stack **stack_a);
int			is_sorted(t_stack *stack);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		select_way(t_stack **stack_a, t_stack **stack_b, int stack_size);
t_stack		*set_stack(int ac, char **av);
void		shortest_move(t_stack **stack_a, t_stack **stack_b);
void		sort_three(t_stack **stack_a);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_other(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		search_target_pos(t_stack **stack_a, t_stack **stack_b);
void		sort_over_500(t_stack **stack_a, t_stack **stack_b);
void		double_free(char **argv);
int			double_free_and_error(char	**argv, int dq_flag);
#endif