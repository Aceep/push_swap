#Project name 
NAME = push_swap

#Compiler
CC = cc 
CFLAGS = -Wall -Wextra -Werror

#Remove
RM = rm -rf

#Librairies
LIB_DIR = ./libft
LIBFT = ./libft/all_libft.a
LDFLAGS = -L $(LIB_DIR) -lft

#Includes
INCLUDES_DIR = ./includes
INCLUDES += -I $(INCLUDES_DIR)
INCLUDES += -I $(LIB_DIR)/includes

#Headers 
HEADERS += push_swap.h 
vpath %.h $(INCLUDES_DIR)

#Sources Directories
PUSH_DIR = ./push_swp
CHECK_DIR = ./checker

#Sources 
SRCS += push_swap.c
SRCS += error_message.c
SRCS += check_arg.c

#Vpath Sources
vpath %.c $(PUSH_DIR)
vpath %.c $(CHECK_DIR)

#Objects
OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
#CHECK_OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(CHECK_SRCS))

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

fclean : lclean clean
	@$(RM) $(NAME)

