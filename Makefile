# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiwata <hiwata@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 21:56:22 by hiwata            #+#    #+#              #
#    Updated: 2021/07/21 17:17:57 by hiwata           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAG = -Wall -Werror -Wextra

NAME = minitalk 

NAME1 = server
SSRC = server.c

NAME2 = client
CSRC = client.c


all : $(NAME1) $(NAME2)

$(NAME) : all

$(NAME1) : 
	 		@$(CC) $(CFLAG) $(SSRC) -I minitalk.h -o $(NAME1)

$(NAME2) : 
	 		@$(CC) $(CFLAG) $(CSRC) -I minitalk.h  -o $(NAME2)
			

# all : $(NAME)

clean :
		rm -rf server.o client.o

fclean : clean
		rm -rf $(NAME1) $(NAME2)

re : fclean all


.PHONEY: all clean fclean re