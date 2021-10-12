# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:40:11 by user42            #+#    #+#              #
#    Updated: 2021/10/12 15:04:44 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

CC = clang

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 -fno-omit-frame-pointer -I includes/ -I libft/includes/
# -fsanitize=address -g3 -fno-omit-frame-pointer 
LIBFT = -L libft -lft

HEADER = ft_nm.h

MAIN = main utilities
HANDLERS = handler_x32 handler_x64 handler_fatelf
NM32 = sym_print sym_sort sym_type
NM64 = sym_print sym_sort sym_type
READELF32 = header_display section_display segment_display symbol_display
READELF64 = header_display section_display segment_display symbol_display

SRCS =	$(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
		$(addsuffix .c, $(addprefix srcs/handlers/, $(HANDLERS))) \
		$(addsuffix .c, $(addprefix srcs/nm_format_x32/, $(NM32))) \
		$(addsuffix .c, $(addprefix srcs/nm_format_x64/, $(NM64))) \
		$(addsuffix .c, $(addprefix srcs/readelf_format_x32/, $(READELF32))) \
		$(addsuffix .c, $(addprefix srcs/readelf_format_x64/, $(READELF64)))

OBJS = ${SRCS:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft/
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o:%.c
				${CC} ${CFLAGS} -c $< -o $@

clean:
				make clean -C libft
				rm -f $(OBJS)

fclean:
				make fclean -C libft
				rm -f $(OBJS)
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
