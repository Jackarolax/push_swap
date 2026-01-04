/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 07:59:07 by anematol          #+#    #+#             */
/*   Updated: 2025/08/27 09:10:41 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(t_stack **stack_a)
{
	int	first_i;
	int	second_i;
	int	third_i;

	first_i = (*stack_a)->i;
	second_i = (*stack_a)->next->i;
	third_i = (*stack_a)->next->next->i;
	if (first_i < second_i && second_i < third_i)
		return ;
	if (first_i < third_i && third_i < second_i)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (second_i < first_i && first_i < third_i)
		sa(stack_a);
	else if (third_i < first_i && first_i < second_i)
		rra(stack_a);
	else if (second_i < third_i && third_i < first_i)
		ra(stack_a);
	else if (third_i < second_i && second_i < first_i)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

//only works on indexed stacks
int	get_smallest_node_position(t_stack **stack)
{
	t_stack	*smallest_node;
	int		smallest_node_position;
	int		position;
	t_stack	*temp;

	smallest_node_position = 0;
	position = 0;
	temp = *stack;
	smallest_node = temp;
	while (temp)
	{
		if (temp->i < smallest_node->i)
		{
			smallest_node = temp;
			smallest_node_position = position;
		}
		temp = temp->next;
		position++;
	}
	return (smallest_node_position);
}

int	reverse_or_normal(int position, int stack_len)
{
	if (position * 2 > stack_len)
		return (position - stack_len);
	return (position);
}

void	sort2(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	if (first->i < first->next->i)
		return ;
	else
		return (sa(stack));
}

//will not work on stack a having less than 3 elements
void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	a_len;
	int	smallest_pos;

	a_len = ft_stacksize(*stack_a);
	if (a_len < 2)
		return ;
	if (a_len == 2)
		return (sort2(stack_a));
	if (a_len == 3)
		return (sort3(stack_a));
	smallest_pos = get_smallest_node_position(stack_a);
	smallest_pos = reverse_or_normal(smallest_pos, a_len);
	i = 0;
	while (i < (smallest_pos * ((smallest_pos > 0) - (smallest_pos < 0))))
	{
		if (smallest_pos < 0)
			rra(stack_a);
		else
			ra(stack_a);
		i++;
	}
	pb(stack_a, stack_b);
	sort_small(stack_a, stack_b);
	pa(stack_a, stack_b);
}
