# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:28:31 by mparasku          #+#    #+#              #
#    Updated: 2023/02/28 16:23:36 by mparasku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_END=\033[0m

NAME_CLIENT = client
NAME_SERVER = server

all:$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):
	@cd printf && make all
	@cc -Wall -Wextra -Werror src/client.c printf/libftprintf.a -o $(NAME_CLIENT)
	@echo "$(COLOUR_GREEN)client is done$(COLOUR_END)"
	
$(NAME_SERVER):
	@cc -Wall -Wextra -Werror src/server.c printf/libftprintf.a -o $(NAME_SERVER)
	@echo "$(COLOUR_RED)server is done$(COLOUR_END)"
clean:
	@cd printf && make clean
	@rm -f server
	@rm -f client
	@echo "$(COLOUR_RED)all objects and executable files have been deleted$(COLOUR_END)"

fclean: clean
	@cd printf && make fclean
	@echo "$(COLOUR_RED)all files have been deleted$(COLOUR_END)"


re: fclean all

bonus: fclean
	@cd printf && make all
	@cc -Wall -Wextra -Werror src_bonus/server_bonus.c printf/libftprintf.a -o server
	@echo "$(COLOUR_RED)server_bonus is done$(COLOUR_END)"
	@cc -Wall -Wextra -Werror src_bonus/client_bonus.c printf/libftprintf.a -o client
	@echo "$(COLOUR_GREEN)client_bonus is done$(COLOUR_END)"

.PHONY: all clean fclean re 