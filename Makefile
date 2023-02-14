# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 12:22:29 by tadiyamu          #+#    #+#              #
#    Updated: 2023/01/26 12:22:32 by tadiyamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT = ./libft/libft.a

FILES = ft_push_st \
		ft_rotate_st \
		ft_rrotate_st \
		ft_stack_ops \
		ft_stack_swap \
		push_swap_arg \
		push_swap_instruction \
		push_swap_quick_a \
		push_swap_quick_b \
		push_swap_util \
		push_swap

FILES_B = ft_stack_ops_bonus \
		ft_stack_bonus \
		push_swap_arg_bonus \
		get_next_line_bonus \
		get_next_line_utils_bonus \
		push_swap_excute_bonus \
		push_swap_util_bonus \
		push_swap_bonus

SRCS = $(addsuffix .c, $(FILES))
SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS = $(addsuffix .o, $(FILES))
OBJS_B = $(addsuffix .o, $(FILES_B))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $^ -L./libft -lft

bonus: $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_B) $^ -L./libft -lft

$(LIBFT):
	make -C libft

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C libft
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re
