# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 12:25:00 by alycgaut          #+#    #+#              #
#    Updated: 2023/05/04 15:30:01 by alycgaut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Project Name
NAME = checker

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Remove
RM = rm -rf

# Reset
NC = \033[0m

# Colors
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BBLUE = \033[1;34m
BRED = \033[1;31m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BBLACK = \033[1;30m
BWHITE = \033[1;37m

# One Line Output
OL =\e[1A\r\033[K

#Librairies
LIB_DIR = ../libft
LIBFT = $(LIB_DIR)/libft.a
LDFLAGS = -L $(LIB_DIR) -lft

#Includes
#INCLUDES += -I checker.h
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

#Counter
TOTAL = $(words $(SRCS))
COUNT = 0

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
	@if [ $(COUNT) = 0 ]; then echo ""; fi
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\t$(CYAN)Compiling %s$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT) $<

#Object Directory
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

#Clean 
clean:
	@$(RM) $(OBJS_DIR)

re : fclean all