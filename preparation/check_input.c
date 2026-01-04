/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:28:50 by anematol          #+#    #+#             */
/*   Updated: 2025/09/01 13:10:17 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	contains_empty_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

//one space before first num is valid,
//multiple spaces at start or between nums is not
//one + or - sign is valid, multiple signs before. numbers are not
//does not check, if number is a valid integer
int	count_valid_numbers(char *num_str)
{
	int	num_count;
	int	toggle_next_count;
	int	i;

	if (num_str[0] == '\0')
		return (0);
	num_count = 0;
	i = -1;
	toggle_next_count = (!ft_isspace(num_str[0]));
	while (num_str[++i] != '\0')
	{
		if (toggle_next_count && (ft_isdigit(num_str[i])
				|| (ft_issign(num_str[i]) && ft_isdigit(num_str[i + 1]))))
		{
			num_count++;
			toggle_next_count = 0;
		}
		else if (!toggle_next_count && ft_isspace(num_str[i]))
			toggle_next_count = 1;
		else if (!toggle_next_count && ft_isdigit(num_str[i]))
			continue ;
		else
			return (-1);
	}
	return (num_count);
}

//just ft_atoi, but it returns a 1 if num is in int bounds and 0 if it isnt
int	check_valid_int(const char *num_str)
{
	long long	num;
	int			i;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(num_str[i]))
		i++;
	if (num_str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (num_str[i] == '+')
		i++;
	while (ft_isdigit(num_str[i]) && num <= INT_MAX)
	{
		num = (num * 10) + (num_str[i] - '0');
		i++;
	}
	if (ft_isdigit(num_str[i]))
		return (0);
	num *= sign;
	return ((num >= INT_MIN && num <= INT_MAX));
}
