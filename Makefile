# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabre <msabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 15:08:28 by kbessa            #+#    #+#              #
#    Updated: 2019/11/30 16:22:46 by msabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap

NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= main_ps.c parse_mas.c bonus.c checker.c create_stack.c double_commands.c helper_functions.c insert_sort.c print_errors.c push.c rev_reverse.c reverse.c sort_five.c sort_hundred.c sort_three.c stacks_function.c swap.c

SRC2 	= main_checker.c parse_mas.c bonus.c checker.c create_stack.c double_commands.c  helper_functions.c insert_sort.c print_errors.c push.c rev_reverse.c reverse.c sort_five.c sort_hundred.c sort_three.c stacks_function.c swap.c

LIBFT   = ./includes/libft

OBJPATH = objects

DEFS = ./includes/push_swap.h

GREEN:="\033[1;32m"

ANSI_COLOR_RESET:="\x1b[0m"

OBJS1 	= $(addprefix $(OBJPATH)/,$(SRC1:.c=.o))

OBJS2 	= $(addprefix $(OBJPATH)/,$(SRC2:.c=.o))

LIB_BINARY	= ./includes/libft/libft.a

all: $(LIB_BINARY) $(NAME1) $(NAME2)

$(OBJPATH):
	@mkdir $@

$(OBJPATH)/%.o: %.c | $(OBJPATH)
	@$(CC) $(CFLAGS) -c $< -o $@


$(LIB_BINARY):
	@make -C $(LIBFT)

$(NAME1): $(OBJS1) $(LIB_BINARY) $(DEFS)
	@gcc $(OBJS1) $(LIB_BINARY) -o $@
	@echo $(GREEN)"     $(NAME1) is ready"$(ANSI_COLOR_RESET)


$(NAME2): $(OBJS2) $(LIB_BINARY) $(DEFS)
	@gcc $(OBJS2) $(LIB_BINARY) -o $@
	@echo $(GREEN)"     $(NAME2) is ready"$(ANSI_COLOR_RESET)


clean:
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJPATH)
	@make -C ./includes/libft clean

fclean: clean
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)
	@make -C ./includes/libft fclean

re: fclean all
