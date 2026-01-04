/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_index_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:32:04 by anematol          #+#    #+#             */
/*   Updated: 2025/09/01 09:55:22 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_both_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
}

int	contains_duplicates(t_stack *num_stack_node)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!num_stack_node)
		return (-1);
	temp = num_stack_node;
	while (temp->next)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->number == temp2->number)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

//assumes the stack does not contain duplicates
//works on unindexed stacks
static t_stack	*find_smallest_node(t_stack *numstack, long long last_num)
{
	t_stack		*temp;
	t_stack		*smallest_node;
	long long	smallest_num;

	temp = numstack;
	smallest_num = 2147483648;
	while (temp)
	{
		if (temp->number > last_num && temp->number < smallest_num)
		{
			smallest_node = temp;
			smallest_num = (long long) smallest_node->number;
		}
		temp = temp->next;
	}
	return (smallest_node);
}

t_stack	*numstr_to_numstack(char *num_str)
{
	t_stack	*num_stack;
	int		toggle_new_num;
	t_stack	*temp;

	if (count_valid_numbers(num_str) <= 0)
		return (NULL);
	num_stack = ft_stacknew(ft_atoi(num_str));
	if (!num_stack || !check_valid_int(num_str))
		return (ft_stackclear(&num_stack), NULL);
	toggle_new_num = 0;
	while (*(++num_str))
	{
		if (toggle_new_num && (ft_isdigit(*num_str) || ft_issign(*num_str)))
		{
			temp = ft_stacknew(ft_atoi(num_str));
			ft_stackadd_back(&num_stack, temp);
			if (!temp || !check_valid_int(num_str))
				return (ft_stackclear(&num_stack), NULL);
			toggle_new_num = 0;
		}
		else if (!toggle_new_num && ft_isspace(*num_str))
			toggle_new_num = 1;
	}
	return (num_stack);
}

//assumes the stack does not contain duplicates
void	add_indexes(t_stack *num_stack)
{
	long long	last_num;
	t_stack		*smallest_node;
	int			stack_len;
	int			i;

	last_num = -2147483649;
	stack_len = ft_stacksize(num_stack);
	i = 0;
	while (i < stack_len)
	{
		smallest_node = find_smallest_node(num_stack, last_num);
		smallest_node->i = i;
		last_num = smallest_node->number;
		i++;
	}
}
