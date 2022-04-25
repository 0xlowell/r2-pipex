# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 22:33:15 by lzima             #+#    #+#              #
#    Updated: 2022/04/05 23:54:52 by lzima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC					=	child_process.c \
						utils_pipex.c \
						utils_pipex_libft_1.c \
						utils_pipex_libft_2.c \
						main.c

OBJS				=	$(SRC:.c=.o)

CC					= 	gcc
RM					=	rm -f
CFLAGS				= 	-Wall -Wextra -Werror -g -fsanitize=address


NAME				= pipex


$(NAME):		$(OBJS)
						$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
#.c.o:
#						${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

