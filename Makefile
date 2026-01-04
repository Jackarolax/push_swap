# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 09:33:26 by anematol          #+#    #+#              #
#    Updated: 2025/09/01 11:27:44 by anematol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES =	lib_functions/mini_libft.c\
			lib_functions/ft_strjoin.c\
			lib_functions/stack_libft.c\
			preparation/check_input.c\
			preparation/prepare_index_stack.c\
			execute_operations/stack_operations.c\
			execute_operations/push.c\
			execute_operations/rotate.c\
			execute_operations/reverse_rotate.c\
			execute_operations/swap.c\
			sorting/small_push_swap.c\
			sorting/cost_options.c\
			sorting/possible_actions.c\
			sorting/stack_functions.c\
			sorting/turk.c\
			main.c

CFILESBONUS =	lib_functions/mini_libft.c\
				lib_functions/ft_strjoin.c\
				lib_functions/stack_libft.c\
				preparation/check_input.c\
				preparation/prepare_index_stack.c\
				execute_operations/stack_operations.c\
				checker_functions/checker.c\
				checker_functions/get_next_line.c\
				checker_functions/get_next_line_utils.c

CFLAGS = -Wextra -Werror -Wall

NAME = push_swap

NAMEBONUS = checker

all: $(NAME)

bonus: $(NAMEBONUS)

$(NAMEBONUS):
		cc $(CFLAGS) $(CFILESBONUS) -o $(NAMEBONUS)

$(NAME):
		cc $(CFLAGS) $(CFILES) -o $(NAME)

clean:
		rm -f $(NAME)

re: clean all

cleanbonus:
		rm -f $(NAMEBONUS)

fclean: clean cleanbonus

rebonus: cleanbonus bonus

