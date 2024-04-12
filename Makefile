# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 06:51:45 by emansoor          #+#    #+#              #
#    Updated: 2024/04/12 07:56:34 by emansoor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = push_swap.c \
		swap_push_rotate.c \
		reverse_rotate.c \
		validate_input.c \
		utils.c \
		sort_three.c \
		sort_five.c \
		sort_five_utils.c \
		sorting_utils.c \
		set_indexes.c \
		bucket_sort.c \
		bucket_sort_utils.c \
		sort_small.c \
		sort_big.c \
		push_to_b.c \
		cleanup.c

OFILES = $(CFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OFILES)
	make -C ./libft
	make bonus -C ./libft
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)
	
clean:
	make -C ./libft clean
	rm -f $(OFILES)
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re