# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 17:57:36 by ccompote          #+#    #+#              #
#    Updated: 2022/12/23 17:57:39 by ccompote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = Bonus/checker

SRCS =  a_foreplay.c \
b_culmination.c \
check.c \
fs_for_b_culmination.c \
fs_for_b_culmination_2.c \
fs_str.c \
ft_atoi.c \
ft_split.c \
itoa.c \
list_fuctions.c \
list_fuctions_2.c \
list_fuctions_3.c \
main.c \
operations.c \
operations_b.c \
operations_push.c \
operations_swap.c \
steps_for_b_culmination.c

SRCS_B = Bonus/check.c \
Bonus/fs_str.c \
Bonus/ft_atoi.c \
Bonus/ft_split.c \
Bonus/ft_strncmp.c \
Bonus/get_next_line.c \
Bonus/get_next_line_utils.c \
Bonus/itoa.c \
Bonus/list_fuctions.c \
Bonus/list_fuctions_2.c \
Bonus/list_fuctions_3.c \
Bonus/main.c


OBJ	= $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)
 
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $^ -o $@

bonus : $(SRCS_B) $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)
	@mv $(NAME_B) .

clean :
	@rm -f $(OBJ) $(OBJ_B) bonus_exec
	
fclean : clean
	@rm -f $(NAME) checker
		
re : fclean all

.PHONY : all clean fclean re bonus