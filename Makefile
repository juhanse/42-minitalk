# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:56:02 by juhanse           #+#    #+#              #
#    Updated: 2025/01/07 12:00:47 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

CLIENT = client
SERVER = server
HEADER = minitalk.h

SRCS_CLIENT = srcs/client.c lib/ft_atoi.c lib/ft_printf.c
SRCS_SERVER = srcs/server.c lib/ft_atoi.c lib/ft_printf.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(CLIENT) $(SERVER)

fclean: clean
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
