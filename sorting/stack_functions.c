/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:29:38 by anematol          #+#    #+#             */
/*   Updated: 2025/09/01 10:19:48 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_position(t_stack **stack, int i)
{
	int		position;
	t_stack	*temp;

	position = -1;
	temp = *stack;
	while (temp)
	{
		position++;
		if (temp->i == i)
			return (position);
		temp = temp->next;
	}
	return (position);
}

//look for biggest number, thats still smaller than node_a
//does calculate optimal rotation yet
int	get_rotation_b(t_stack *node_a, t_stack **stack_b)
{
	int		nearest_smaller_i;
	long	nearest_larger_i;
	t_stack	*temp;

	temp = *stack_b;
	nearest_smaller_i = -1;
	nearest_larger_i = 2147483648;
	while (temp)
	{
		if (temp->i < node_a->i && temp->i > nearest_smaller_i)
			nearest_smaller_i = temp->i;
		if (temp->i > node_a->i && temp->i < nearest_larger_i)
			nearest_larger_i = temp->i;
		temp = temp->next;
	}
	if (nearest_smaller_i == -1 && nearest_larger_i == 2147483648)
		return (0);
	if (nearest_larger_i == 2147483648)
		return (get_position(stack_b, nearest_smaller_i));
	if (nearest_smaller_i == -1)
		return (get_position(stack_b, (int)nearest_larger_i) + 1);
	return (get_position(stack_b, nearest_smaller_i));
}

int	is_sorted(t_stack	**stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (!(i == temp->i))
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

void	rotate_b_accordingly(t_stack **stack_b, int b_size)
{
	int	rotate_b;
	int	largest_b_node_pos;

	largest_b_node_pos = (get_smallest_node_position(stack_b) + 1) % b_size;
	if ((largest_b_node_pos) * 2 < b_size)
		rotate_b = largest_b_node_pos;
	else
		rotate_b = largest_b_node_pos - b_size;
	if (rotate_b < 0)
	{
		while (rotate_b < 0)
		{
			rrb(stack_b);
			rotate_b++;
		}
	}
	else
	{
		while (rotate_b > 0)
		{
			rb(stack_b);
			rotate_b--;
		}
	}
}

void	push_everything_left_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	a_len_before;

	a_len_before = ft_stacksize(*stack_a);
	while (a_len_before > 0)
	{
		while (*stack_b && (*stack_b)->i > ft_stacklast(*stack_a)->i)
			pa(stack_a, stack_b);
		rra(stack_a);
		a_len_before--;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
