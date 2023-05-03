# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 12:25:00 by alycgaut          #+#    #+#              #
#    Updated: 2023/05/03 16:46:13 by alycgaut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Project Name
NAME = checker

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Remove
RM = rm -rf

#Librairies
LIB_DIR = ../libft
LIBFT = $(LIB_DIR)/libft.a
LDFLAGS = -L $(LIB_DIR) -lft

#Includes
INCLUDES += -I checker.h
INCLUDES += -I $(LIB_DIR)/includes
INCLUDES += -I ../includes

#HEADERS
HEADERS += checker.h
vpath %.h $(INCLUDES_DIR)

#Sources
SRCS += checker.c
SRCS += create_list.c
SRCS += check_arg.c
SRCS += stack_utils.c
SRCS += error_message.c
SRCS += swap.c
SRCS += rotate.c
SRCS += rotate_reverse.c
SRCS += push.c

#Source Dir
PUSH_DIR = ../push
vpath %.c $(PUSH_DIR)

#Objects
OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

#Rules
all: $(NAME)
	@mv checker ..

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) $(INCLUDES) -o $@

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#Object Directory
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

#Clean 
clean:
	@$(RM) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all