/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:49:00 by anematol          #+#    #+#             */
/*   Updated: 2025/09/01 10:59:38 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_stacks_and_sort(t_stack *first_a, t_stack *first_b)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	first_b = NULL;
	stack_a = &first_a;
	stack_b = &first_b;
	if (contains_duplicates(*stack_a))
	{
		ft_stackclear(stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	add_indexes(*stack_a);
	turk(stack_a, stack_b);
	ft_stackclear(stack_a);
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
			return (write(2, "Error\n", 6), 1);
		malloced = 1;
	}
	else if (argc == 2)
		numstr = argv[1];
	else
		return (0);
	first_a = numstr_to_numstack(numstr);
	if (malloced)
		free(numstr);
	if (!first_a)
		return (write(2, "Error\n", 6), 1);
	handle_stacks_and_sort(first_a, NULL);
	return (0);
}
