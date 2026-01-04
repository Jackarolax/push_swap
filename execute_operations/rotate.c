/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:05:43 by anematol          #+#    #+#             */
/*   Updated: 2025/08/27 09:01:15 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **stack_a)
{
	rotate(stack_a, 0);
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b, 0);
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	write(1, "rr\n", 3);
	return ;
}
