/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 08:01:33 by anematol          #+#    #+#             */
/*   Updated: 2025/08/28 10:13:53 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_next;

	if (!stack)
		return (NULL);
	if (ft_stacksize(*stack) < 2)
		return (*stack);
	temp = *stack;
	temp_next = temp->next;
	temp->next = temp_next->next;
	temp_next->next = temp;
	*stack = temp_next;
	return (*stack);
}

//reverse = 1 -> reverse rotate, 0 -> normal rotate
t_stack	*rotate(t_stack **stack, int reverse)
{
	t_stack	*temp_first;
	t_stack	*temp_second;
	t_stack	*temp_before_last;
	t_stack	*temp_last;

	if (!stack)
		return (NULL);
	if (ft_stacksize(*stack) < 2)
		return (*stack);
	temp_first = *stack;
	temp_second = temp_first->next;
	temp_before_last = *stack;
	while (temp_before_last->next->next)
		temp_before_last = temp_before_last->next;
	temp_last = temp_before_last->next;
	temp_last->next = temp_first;
	if (reverse)
	{
		temp_before_last->next = NULL;
		*stack = temp_last;
		return (temp_last);
	}
	temp_first->next = NULL;
	*stack = temp_second;
	return (temp_second);
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp_first_from;
	t_stack	*temp_second_from;
	t_stack	*temp_first_to;

	if (!from || !(*from))
		return ;
	temp_first_from = *from;
	temp_second_from = temp_first_from->next;
	temp_first_to = *to;
	temp_first_from->next = temp_first_to;
	*from = temp_second_from;
	*to = temp_first_from;
}
