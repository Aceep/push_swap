# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 16:40:43 by alycgaut          #+#    #+#              #
#    Updated: 2023/05/04 15:32:04 by alycgaut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Project name 
NAME = push_swap

#Compiler
CC = cc 
CFLAGS = -Wall -Wextra -Werror

#Remove
RM = rm -rf

#Librairies
LIB_DIR = ./libft
LIBFT = ./libft/libft.a
LDFLAGS = -L $(LIB_DIR) -lft

#Includes
INCLUDES_DIR = ./includes
INCLUDES += -I $(INCLUDES_DIR)
INCLUDES += -I $(LIB_DIR)/includes

#Headers 
HEADERS += push_swap.h 
vpath %.h $(INCLUDES_DIR)

#Sources Directories
PUSH_DIR = ./push
CHECK_DIR = ./checker_dir

#Sources 
SRCS += check_arg.c
SRCS += cost.c
SRCS += create_list.c
SRCS += error_message.c
SRCS += main.c
SRCS += position.c
SRCS += push_swap.c
SRCS += push.c
SRCS += rotate_reverse.c
SRCS += rotate.c
SRCS += sort_position.c
SRCS += stack_utils.c
SRCS += swap.c
SRCS += sort_three.c

#Vpath Sources
vpath %.c $(PUSH_DIR)

#Objects
OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

#Rules
all: $(LIBFT) $(NAME)
	@echo "all done"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) $(INCLUDES) -o $@

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#Rule Libft
$(LIBFT):
	@make --no-print-directory -C $(LIB_DIR)

#Object Directory
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

#Clean Lib
lclean : 
	@make --no-print-directory fclean -C $(LIB_DIR)

#Clean 
clean:
	@$(RM) $(OBJS_DIR)

#Clean Objets and Exe
fclean : clean
	@$(RM) $(NAME)

#Clean All
aclean : fclean lclean
	@$(RM) checker
	@make --no-print-directory -C $(CHECK_DIR) clean

re : fclean all

#Compile Checker
bonus : all
	@make --no-print-directory -C $(CHECK_DIR)
	