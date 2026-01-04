/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:09:18 by anematol          #+#    #+#             */
/*   Updated: 2025/09/01 09:38:23 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **stack_a)
{
	rotate(stack_a, 1);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_stack **stack_b)
{
	rotate(stack_b, 1);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 1);
	rotate(stack_b, 1);
	write(1, "rrr\n", 4);
	return ;
}
