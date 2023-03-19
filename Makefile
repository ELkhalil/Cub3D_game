# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 15:53:10 by aelkhali          #+#    #+#              #
#    Updated: 2023/03/19 14:29:19 by aelkhali         ###   ########.fr        #
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

# iclude libft Makefile
LIBFT_PATH = cd ./libft
LIBFT = ./libft/libft.a
PARS_SRCS = ./srcs/parsing/parser.c ./srcs/parsing/parser_utils_1.c ./srcs/parsing/rgb_colors_utils.c\
			./srcs/parsing/map.c srcs/parsing/map_utils.c ./srcs/parsing/map_utils2.c 

# loading source files :
SRCS = main.c $(PARS_SRCS) 

all : $(NAME)
	@echo "You Can Start Playing $(GREEN)*** $(NAME) ***"

$(NAME) : $(SRCS)
	@$(LIBFT_PATH) && make
	@$(CC) $(FLAGS) $(MLX) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)Compiling the source files... $(STOP)"

clean :
	@$(LIBFT_PATH) && make clean
	@echo "$(YELLOW)Cleaning... $(STOP)"

fclean : clean
	@$(LIBFT_PATH) && make fclean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting The Game ... $(STOP)"

re : fclean all