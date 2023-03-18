# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 11:17:28 by aelkhali          #+#    #+#              #
#    Updated: 2023/03/18 10:25:43 by aelkhali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###-----------------Variables-----------------###
NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

#FILES------
CFILES = ft_putstr.c ft_split.c ft_strchr.c ft_strjoin.c ft_strcmp.c ft_strlcpy.c ft_strlen.c \
		ft_substr.c get_next_line.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_strncmp.c \
		ft_strrchr.c ft_strtrim.c ft_strdup.c ft_isdigit.c ft_atoi.c
			
OBJS = $(CFILES:.c=.o)

RM = rm -rf

AR = ar -rc

###-----------------Rules-----------------###
all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "libft.a created successfully..."

.c.o :
	@cc $(FLAGS) -c $< -o $@

clean :
#	@echo "cleaning the object files..."
	@$(RM) $(OBJS)

fclean : clean
#	@echo "cleaning Everything..."
	@$(RM) $(NAME)

re : fclean all
