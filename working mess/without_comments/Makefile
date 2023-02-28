# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:28:31 by mparasku          #+#    #+#              #
#    Updated: 2023/02/27 17:25:25 by mparasku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary Name:
NAME	=
CLIENT	=	client
SERVER	=	server

#ft_printf Variables:
LIBFTPRINTF	=	printf/libftprintf.a 
LIBFTPRINTF_DIR	=	printf

#minitalk variables
SRC_C	=	client.c
SRC_S	=	server.c
OBJ_S	=	server.o
OBJ_C	=	client.o
INC		=	minitalk.h

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_S)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_C)
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re