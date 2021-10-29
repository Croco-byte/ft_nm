# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:40:11 by user42            #+#    #+#              #
#    Updated: 2021/10/14 11:11:59 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I includes/
# -fsanitize=address -g3 -fno-omit-frame-pointer 

HEADER = ft_nm.h

MAIN = main utilities
HANDLERS = handler_x32 handler_x64 handler_fatelf
NM32 = sym_print sym_sort sym_type type_helpers
NM64 = sym_print sym_sort sym_type type_helpers
READELF32 = display header_display section_display segment_display symbol_display
READELF64 = display header_display section_display segment_display symbol_display

SRCS =	$(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
		$(addsuffix .c, $(addprefix srcs/handlers/, $(HANDLERS))) \
		$(addsuffix .c, $(addprefix srcs/nm_format_x32/, $(NM32))) \
		$(addsuffix .c, $(addprefix srcs/nm_format_x64/, $(NM64))) \
		$(addsuffix .c, $(addprefix srcs/readelf_format_x32/, $(READELF32))) \
		$(addsuffix .c, $(addprefix srcs/readelf_format_x64/, $(READELF64)))

OBJS = ${SRCS:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o:%.c
				${CC} ${CFLAGS} -c $< -o $@

clean:
				rm -f $(OBJS)

fclean:
				rm -f $(OBJS)
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
