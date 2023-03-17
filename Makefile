# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 15:53:10 by aelkhali          #+#    #+#              #
#    Updated: 2023/03/17 20:42:47 by aelkhali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Game Name
NAME = cub3D

# Colors :
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED= \033[0;31m
BLUE = \033[0;34m
STOP = \033[0m

# Commands And Flags :
CC = cc 
FLAGS =	-Wall -Wextra -Werror # -fsanitize=address -g
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

# loading source files :
LIBFT = ./libft/ft_putstr.c ./libft/ft_split.c ./libft/ft_strchr.c ./libft/ft_strjoin.c \
	./libft/ft_strcmp.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_substr.c ./libft/get_next_line.c \
	./libft/ft_putnbr_fd.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_strncmp.c \
	./libft/ft_strrchr.c

SRCS = $(LIBFT) main.c ./srcs/parsing/parser.c

all : $(NAME)
	@echo "You Can Start Playing $(GREEN)*** $(NAME) ***"

$(NAME) : $(SRCS)
	@$(CC) $(FLAGS) $(MLX) $(SRCS) -o $(NAME)
	@echo "$(BLUE)Compiling the source files... $(STOP)"

clean :
	@$(RM) $(NAME)
	@echo "$(YELLOW)Cleaning... $(STOP)"

fclean : clean
	@echo "$(RED)Deleting The Game ... $(STOP)"

re : fclean all