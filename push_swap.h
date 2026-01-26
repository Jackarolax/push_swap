/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:49:17 by anematol          #+#    #+#             */
/*   Updated: 2025/08/30 16:23:13 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				i;
	int				rotation_a;
	int				rotation_b;
	unsigned int	cost;
	struct s_stack	*next;
}	t_stack;

typedef struct s_cost
{
	unsigned int	r_r;
	unsigned int	rr_rr;
	unsigned int	r_rr;
	unsigned int	rr_r;
	int				rotation_a;
	int				rotation_b;
	unsigned int	optimal_cost;
}	t_cost;

typedef struct s_act
{
	unsigned int	ss;
	unsigned int	sa;
	unsigned int	sb;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	rr;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rrr;
	unsigned int	rra;
	unsigned int	rrb;
}	t_act;

//mini_libft (lib_functions)
int		ft_isspace(char c);
int		ft_isdigit(char c);
int		ft_issign(char c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);

//ft_strjoin (lib_functions)
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(int size, char **strs, char *sep);

//stack_libft (lib_functions)
t_stack	*ft_stacknew(int number);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);

//check_input (preparation)
int		contains_empty_args(int argc, char **argv);
int		count_valid_numbers(char *num_str);
int		check_valid_int(const char *num_str);
void	error(void);

//prepare_indexstack (preparation)
void	clear_both_stacks(t_stack **stack_a, t_stack **stack_b);
int		contains_duplicates(t_stack *num_stack_node);
t_stack	*numstr_to_numstack(char *num_str);
void	add_indexes(t_stack *num_stack);

//operations (execute_operations)
t_stack	*swap(t_stack **stack_a);
t_stack	*rotate(t_stack **stack, int reverse);
void	push(t_stack **from, t_stack **to);

//rotate (execute_operations)
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_a);
void	rr(t_stack **stack_a, t_stack **stack_b);

//reverse_rotate (execute_operations)
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//push (execute_operations)
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

//swap (execute_operations)
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_a);
void	ss(t_stack **stack_a, t_stack **stack_b);

//small_push_swap (sorting)
int		get_smallest_node_position(t_stack **stack);
void	sort2(t_stack **stack);
void	sort3(t_stack **stack);
void	sort_small(t_stack **stack_a, t_stack **stack_b);

//cost_options (sorting)
t_cost	init_cost_options(int pos[2], int sizes[2]);
void	set_optimal_cost_per_node(t_stack *node_a, int pos[2], int sizes[2]);
void	calculate_optimal_costs(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_smallest_cost_node(t_stack **stack_a);

//possible_actions (sorting)
int		min(int a, int b);
int		max(int a, int b);
t_act	init_count_actions_include_same_rots(int rot_a, int rot_b);
t_act	count_all_actions(t_stack *node_a);
void	perform_actions(t_stack *node_a, t_stack **stack_a, t_stack **stack_b);

//stack_functions (sorting)
int		get_position(t_stack **stack, int i);
int		get_rotation_b(t_stack *node_a, t_stack **stack_b);
int		is_sorted(t_stack	**stack);
void	rotate_b_accordingly(t_stack **stack_b, int b_size);
void	push_everything_left_to_a(t_stack **stack_a, t_stack **stack_b);

//turk (sorting)
void	turk(t_stack **stack_a, t_stack **stack_b);
#endif
