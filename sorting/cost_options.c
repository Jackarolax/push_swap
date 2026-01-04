/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:24:17 by anematol          #+#    #+#             */
/*   Updated: 2025/08/27 09:07:48 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cost	init_cost_options(int pos[2], int sizes[2])
{
	t_cost	cost;
	int		rpos_a;
	int		rpos_b;

	rpos_a = sizes[0] - pos[0];
	rpos_b = sizes[1] - pos[1];
	cost.r_r = pos[0] * (pos[0] > pos[1]) + pos[1] * (pos[0] <= pos[1]);
	cost.optimal_cost = cost.r_r;
	cost.rotation_a = pos[0];
	cost.rotation_b = pos[1];
	cost.rr_rr = rpos_a * (rpos_a > rpos_b) + rpos_b * (rpos_a <= rpos_b);
	cost.r_rr = pos[0] + rpos_b;
	cost.rr_r = rpos_a + pos[1];
	return (cost);
}

void	set_optimal_cost_per_node(t_stack *node_a, int pos[2], int sizes[2])
{
	t_cost	cost;

	cost = init_cost_options(pos, sizes);
	if (cost.rr_rr < cost.optimal_cost)
	{
		cost.optimal_cost = cost.rr_rr;
		cost.rotation_a = pos[0] - sizes[0];
		cost.rotation_b = pos[1] - sizes[1];
	}
	if (cost.r_rr < cost.optimal_cost)
	{
		cost.optimal_cost = cost.r_rr;
		cost.rotation_a = pos[0];
		cost.rotation_b = pos[1] - sizes[1];
	}
	if (cost.rr_r < cost.optimal_cost)
	{
		cost.optimal_cost = cost.rr_r;
		cost.rotation_a = pos[0] - sizes[0];
		cost.rotation_b = pos[1];
	}
	node_a->rotation_a = cost.rotation_a;
	node_a->rotation_b = cost.rotation_b;
	node_a->cost = cost.optimal_cost;
}

void	calculate_optimal_costs(t_stack **stack_a, t_stack **stack_b)
{
	int		sizes[2];
	int		pos[2];
	t_stack	*temp;

	pos[0] = 0;
	temp = *stack_a;
	sizes[0] = ft_stacksize(*stack_a);
	sizes[1] = ft_stacksize(*stack_b);
	while (temp)
	{
		pos[1] = get_rotation_b(temp, stack_b);
		set_optimal_cost_per_node(temp, pos, sizes);
		pos[0]++;
		temp = temp->next;
	}
}

t_stack	*get_smallest_cost_node(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*smallest_cost_node;

	temp = *stack_a;
	smallest_cost_node = temp;
	while (temp)
	{
		if (temp->cost < smallest_cost_node->cost)
			smallest_cost_node = temp;
		temp = temp->next;
	}
	return (smallest_cost_node);
}
