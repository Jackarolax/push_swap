/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:21:19 by anematol          #+#    #+#             */
/*   Updated: 2025/08/27 09:09:48 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

//will initialize t_count_actions and assign actions if both neg or pos
t_act	init_count_actions_include_same_rots(int rot_a, int rot_b)
{
	t_act	actions;

	actions.rr = 0;
	actions.ra = 0;
	actions.rb = 0;
	actions.rrr = 0;
	actions.rra = 0;
	actions.rrb = 0;
	if (rot_a >= 0 && rot_b >= 0)
	{
		actions.rr = min(rot_a, rot_b);
		actions.ra = rot_a - actions.rr;
		actions.rb = rot_b - actions.rr;
	}
	else if (rot_a <= 0 && rot_b <= 0)
	{
		actions.rrr = -max(rot_a, rot_b);
		actions.rra = -rot_a - actions.rrr;
		actions.rrb = -rot_b - actions.rrr;
	}
	return (actions);
}

t_act	count_all_actions(t_stack *node_a)
{
	t_act	actions;
	int		rot_a;
	int		rot_b;

	rot_a = node_a->rotation_a;
	rot_b = node_a->rotation_b;
	actions = init_count_actions_include_same_rots(rot_a, rot_b);
	if (rot_a < 0 && rot_b >= 0)
	{
		actions.rra = -rot_a;
		actions.rb = rot_b;
	}
	else if (rot_b < 0 && rot_a >= 0)
	{
		actions.ra = rot_a;
		actions.rrb = -rot_b;
	}
	node_a->rotation_a = 0;
	node_a->rotation_b = 0;
	node_a->cost = 0;
	return (actions);
}

void	perform_actions(t_stack *node_a, t_stack **stack_a, t_stack **stack_b)
{
	t_act	actions;

	actions = count_all_actions(node_a);
	while (actions.rr-- > 0)
		rr(stack_a, stack_b);
	while (actions.ra-- > 0)
		ra(stack_a);
	while (actions.rb-- > 0)
		rb(stack_b);
	while (actions.rrr-- > 0)
		rrr(stack_a, stack_b);
	while (actions.rra-- > 0)
		rra(stack_a);
	while (actions.rrb-- > 0)
		rrb(stack_b);
}
