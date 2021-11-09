# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamigore <tamigore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 16:16:11 by tamigore          #+#    #+#              #
#    Updated: 2021/11/09 11:43:03 by tamigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = push_swap

LIBFT = libft

DIR_S = srcs/

HEADER = includes/

SOURCES =	main.c		\
			revers.c	\
			swap.c		\
			algo.c		\
			init.c		\
			check.c		\
			sort.c		\
			track.c		\
			radixsort.c	\
			rrevers.c

SRCS = $(addprefix $(DIR_S),$(SOURCES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I $(HEADER) -g -fsanitize=address

FLAGS = -L $(LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)

norme:
	norminette ./$(LIBFT)
	@echo
	norminette ./$(HEADER)
	@echo
	norminette ./$(DIR_S)

bonus: all

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
