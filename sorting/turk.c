/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:36:16 by anematol          #+#    #+#             */
/*   Updated: 2025/08/27 15:16:29 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	turk(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_cost_node;
	int		total_size;

	total_size = ft_stacksize(*stack_a);
	if (total_size == 1 || is_sorted(stack_a))
		return ;
	if (total_size == 2)
		return (sort2(stack_a));
	if (total_size < 15)
		return (sort_small(stack_a, stack_b));
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (ft_stacksize(*stack_a) > total_size / 10)
	{
		calculate_optimal_costs(stack_a, stack_b);
		smallest_cost_node = get_smallest_cost_node(stack_a);
		perform_actions(smallest_cost_node, stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	rotate_b_accordingly(stack_b, ft_stacksize(*stack_b));
	sort_small(stack_a, stack_b);
	push_everything_left_to_a(stack_a, stack_b);
}
