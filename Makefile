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

#Counter
TOTAL = $(words $(SRCS))
COUNT = 0

#Objects
OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

#Rules
all: $(LIBFT) $(NAME)
	@echo "$(BYELLOW)Push_Swap is ready ! ->$(NC)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) $(INCLUDES) -o $@

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@if [ $(COUNT) = 0 ]; then echo ""; fi
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\t$(CYAN)Compiling %s$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT) $<

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
bonus : $(LIBFT) $(NAME)
	@make --no-print-directory -C $(CHECK_DIR)
	@echo "$(BGREEN)Push_Swap and the checker are ready ! ->$(NC)"