# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 21:08:44 by lrichard          #+#    #+#              #
#    Updated: 2021/06/24 22:13:36 by lrichard         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCSCLIENT		= client.c utils.c

SRCSSERVER		= server.c utils.c

SRCSCLIENTBONUS	= BONUS/client_bonus.c utils.c

SRCSSERVERBONUS = BONUS/server_bonus.c utils.c

OBJSCLIENT		= $(SRCSCLIENT:.c=.o) 

OBJSSERVER		= $(SRCSSERVER:.c=.o)

OBJSCLIENTBONUS	= $(SRCSCLIENTBONUS:.c=.o)
	
OBJSSERVERBONUS	= $(SRCSSERVERBONUS:.c=.o)

HEADER			= minitalk.h

NAME1			= client

NAME2			= server

CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

RM				= rm -f

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

%.o:			BONUS/%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME1) $(NAME2)

bonus:			BONUS/client BONUS/server

$(NAME1):		$(OBJSCLIENT) $(HEADER)
				$(CC) $(CFLAGS) $(OBJSCLIENT) -o $(NAME1)

$(NAME2):		$(OBJSSERVER) $(HEADER)
				$(CC) $(CFLAGS) $(OBJSSERVER) -o $(NAME2)

BONUS/$(NAME1):	$(OBJSCLIENTBONUS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJSCLIENTBONUS) -o BONUS/$(NAME1)

BONUS/$(NAME2):	$(OBJSSERVERBONUS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJSSERVERBONUS) -o BONUS/$(NAME2)

clean:
				$(RM) $(OBJSCLIENT) $(OBJSSERVER) $(OBJSCLIENTBONUS) $(OBJSSERVERBONUS)

fclean:			clean
				$(RM) $(NAME1) $(NAME2) BONUS/$(NAME1) BONUS/$(NAME2)

re:				fclean all

.phony:			all clean fclean re bonus
