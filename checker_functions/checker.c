/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:21:12 by anematol          #+#    #+#             */
/*   Updated: 2025/09/01 10:01:28 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	checker_is_sorted(t_stack	**stack)
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

int	strs_are_same(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	return (0);
}

//do_action differs to perform_actions in that it can do every action
//it doesnt use the struct, will only do it once and it will
//return an error if it can't detect the action
int	do_action(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (!action)
		return (0);
	if (strs_are_same(action, "ss\n"))
		return (swap(stack_a), swap(stack_b), 1);
	if (strs_are_same(action, "sa\n"))
		return (swap(stack_a), 1);
	if (strs_are_same(action, "sb\n"))
		return (swap(stack_b), 1);
	if (strs_are_same(action, "pa\n"))
		return (push(stack_b, stack_a), 1);
	if (strs_are_same(action, "pb\n"))
		return (push(stack_a, stack_b), 1);
	if (strs_are_same(action, "rr\n"))
		return (rotate(stack_a, 0), rotate(stack_b, 0), 1);
	if (strs_are_same(action, "ra\n"))
		return (rotate(stack_a, 0), 1);
	if (strs_are_same(action, "rb\n"))
		return (rotate(stack_b, 0), 1);
	if (strs_are_same(action, "rrr\n"))
		return (rotate(stack_a, 1), rotate(stack_b, 1), 1);
	if (strs_are_same(action, "rra\n"))
		return (rotate(stack_a, 1), 1);
	if (strs_are_same(action, "rrb\n"))
		return (rotate(stack_b, 1), 1);
	return (0);
}

int	handle_stacks_and_check_actions(t_stack *first_a, t_stack *first_b)
{
	char	*line;
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = &first_a;
	stack_b = &first_b;
	add_indexes(*stack_a);
	line = get_next_line(0);
	while (line)
	{
		if (!do_action(line, stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			return (free(line), clear_both_stacks(stack_a, stack_b), 1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (checker_is_sorted(stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (clear_both_stacks(stack_a, stack_b), 0);
}

int	main(int argc, char **argv)
{
	char	*numstr;
	int		malloced;
	t_stack	*first_a;

	malloced = 0;
	if (argc > 2)
	{
		if (contains_empty_args(argc, argv))
			return (write(2, "Error\n", 6), 1);
		numstr = ft_strjoin(argc - 1, argv + 1, " ");
		if (!numstr)
			return (free(numstr), write(2, "Error\n", 6), 1);
		malloced = 1;
	}
	else if (argc == 2)
		numstr = argv[1];
	else
		return (0);
	first_a = numstr_to_numstack(numstr);
	if (malloced)
		free(numstr);
	if (!first_a || contains_duplicates(first_a))
		return (ft_stackclear(&first_a), write(2, "Error\n", 6), 1);
	return (handle_stacks_and_check_actions(first_a, NULL));
}
