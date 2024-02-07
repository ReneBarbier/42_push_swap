# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 20:09:37 by mporras-          #+#    #+#              #
#    Updated: 2023/12/11 17:12:23 by rbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
MANDATORY		=	mandatory
SRC_DIR			=	mandatory
OBJS_DIR		=	mandatory/obj
OBJS_SUBS		=	$(OBJS_DIR)
SRCS			=	ft_printf.c \
					ft_print_str.c \
					ft_print_hex.c \
					ft_print_int.c \
					ft_strdup.c \
					ft_print_ptr.c
OBJS 			=	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

CC			 	= 	gcc
RM			 	= 	rm	-rf
CFLAGS		 	= 	-Wall -Wextra -Werror -c
INCLUDES	 	= 	-I.	mandatory/inc/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS_SUBS) $(OBJS)
	@ar	rcs	$(NAME)	$(OBJS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c mandatory/inc/ft_printf.h
	@$(CC) -Iinc $(CFLAGS) -g -c $< -o $@

$(OBJS_DIR):
	-@mkdir $(OBJS_DIR)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJS_DIR)

re:	fclean $(NAME)

.PHONY: all clean fclean re bonus