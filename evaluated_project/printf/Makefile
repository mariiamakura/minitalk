# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:19:30 by mishamakura       #+#    #+#              #
#    Updated: 2023/02/27 17:24:08 by mparasku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 
FLAGS = -Wall -Wextra -Werror

SRC = 	sources/ft_printf.c\
		sources/ft_printchar.c\
		sources/ft_printhex.c\
		sources/ft_printint.c\
		sources/ft_printper.c\
		sources/ft_printptr.c\
		sources/ft_printstr.c\
		sources/ft_printunsint.c

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	@$(MAKE) all -C ./libft
	@cp ./libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "lib is DONE!"

all: $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ)
	
fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re 
