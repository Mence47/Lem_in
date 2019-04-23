# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtroll <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:28:16 by rtroll            #+#    #+#              #
#    Updated: 2018/11/20 18:36:47 by rtroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE_FILES = *.c

OBJECT_FILES = *.o

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SOURCE_FILES) 
	@ar rc $(NAME) $(OBJECT_FILES)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECT_FILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
